# Describing Load

Load can be described using **load parameters** e.g., requests per second, read/write ratio in the database, active users in a chat room, etc.

## The case of Twitter

They have to handle **12,000** writes per second, and they also have to *fan-out* as one user follows many people. Then they have two ways of implementing these operations:

1. The new tweet goes into *a global collection of tweets*. When a user requests their home timeline, we look up the people they follow -> Find all tweets for each of those users -> Merge all tweets (sorted by time)
```sql
-- This retrieves: All tweet data posted by followed users + All corresponding user data for those users
SELECT tweets.*, users.* FROM tweets
  JOIN users ON tweets.sender_id = users.id -- Join users table to tweets table. Link each tweet to the user who sent it
  JOIN follows ON follows.followee_id = users.id -- Join follows table to users table. Connect each user to their followers and followees
  WHERE follows.follower_id = current_user -- Include tweets from users who are being followed by the current user
```
![[Figure 1-2.png]]

2. **Maintain a CACHE for each users home timeline**--like a *mailbox of tweets for each recipient user*. When a user posts a tweet, we look up the people who follow that user -> insert that new tweet into each of their home timeline caches. This is cheaper because *the result has been computed ahead of time*.

![[Figure 1-3.png]]

The 1st version of Twitter uses approach #1, and later on the company switched to approach #2

However, with people who ave > 1 million followers, this will result in **a lot of writes** to home timelines, and doing this in a timely manner (Twitter tries to deliver tweets to followers *within 5 seconds*) is a significant challenge.

For that reason, Twitter is now **moving to a hybrid of both approaches**: Most people's tweets will be fanned out to home timelines (approach #2) while celebrities' tweets will not be fanned out (approach #1)
