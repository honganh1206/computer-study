Scenario: An user updates their profile picture. The client sends the update request to the leader. The leader receives it, and forwards the data changes to the followers. The leader eventually notifies the client that the update was successful.

![[image-1.png]]

The replication to follower 1 is synchronous: The leader waits until follower 1 confirmed it received the write before reporting back to the user. The replication to follower 2 was asynchronous: *The leader sends the message but does not wait for a response from the follower*.

-> There is quite a delay before follower 2 processes the message, but there are cases when followers might fall behind the leader by several minutes (recovering from failures, network problems, etc.)

Synchronous replication ensures data is up-to-date with the leader, but if the follower does not respond e.g., network failures, the write cannot be processed. The leader then must block all the writes until the synchronous replica is up again.

-> It is impractical for all followers to be synchronous. 

We should always have at least two nodes: The leader and one synchronous follower (semi-synchronous) to ensure data is up-to-date.


