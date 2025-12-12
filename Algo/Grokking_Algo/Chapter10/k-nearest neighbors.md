```ad-summary
• KNN is used for **classification** and **regression** and involves looking at the k-nearest neighbors.
• Classification = categorization into a group.
• Regression = predicting a response (like a number).
• Feature extraction means converting an item (like a fruit or a user) into a list of numbers that can be compared.
• Picking good features is an important part of a successful KNN algorithm.

```

# Classifying oranges vs. grapefruit

![[Pasted image 20231201211322.png]]


# Building a recommendation system

![[Pasted image 20231201211641.png]]

- Users are plotted by similarity, so users with similar taste are plotted

![[Pasted image 20231201211719.png]]

## Feature extraction

- Grab the three fruits based on redness and size

![[Pasted image 20231201212234.png]]


- Measure how close they are to each other using Pythagorean formular

$$
\sqrt{ (x_{1} - x_{2})^{2} +(y_{1} - y_{2})^2  }
$$

=> The distance confirms that **fruit A and fruit B are similar**

![[Pasted image 20231201212559.png]]

- For recommendation system, we can **convert each user to a set of coordinates**

![[Pasted image 20231201212642.png]]


![[Pasted image 20231201213016.png]]

- Distance between Priyanka and Justin


![[Pasted image 20231201213049.png]]

# Regression

- Basic two things to do with KNN:
	- **Classification** - Categorization into a group
	- **Regression** - Predicting a response (like a number)
- Scenario: You open a bakery and make fresh bread everyday with a set of features:
	- Weather on a scale of 1 to 5 (1 = bad, 5 = great).
	- Weekend or holiday? (1 if it’s a weekend or a holiday, 0 otherwise.)
	- Is there a game on? (1 if yes, 0 if no.)
- Past data:

![[Pasted image 20231201214543.png]]

- Supposed today is a weekend with good weather => $(4, 1, 0) = ?$

=> A, B, D, E are the closest one

![[Pasted image 20231201215051.png]]

=> Averaging them using Pythagorean formular => **218.75**

## Picking good features

- Criteria when picking features
	- Features that **directly correlate** to the movies you are recommending
	- Features that **do not have a bias**
- However, **there is no one right answer** => Think about all the different things you need to consider

```ad-tip
title: Number of neighbors to look for
If you have $N$ users, you should look at $\sqrt N$ neighbors

```

---

# Introduction to Machine Learning

## Optical Character Recognition (OCR)

- OCR algorithms measure **lines, points, and curves**
- KNN can be used for computers to **automatically figure out images** by
	1. Go through a lot of images of numbers, and extract features of those numbers.
	2. When you get a new image, extract the features of that image, and see what its nearest neighbors are!


![[Pasted image 20231217143014.png]]


## Building a spam filter

- Spam filters use a simple algorithm called *Naive Bayes classifier*


---
# Exercises

10.1. *Normalization* => Bump up Pinky's rating and compare their ratings on the same scale

10.2. Give more weight to the rating of influencers
- Supposed Joe: 3, David: 4, Wes Anderson: 5
- The mean could be (3 + 4+ 5+ 5) / 5 = 4.4

10.3. Too low