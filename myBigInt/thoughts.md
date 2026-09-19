Here's the thinking.
I've seen implementations online (or atleast thoughts) where the number is simply a string array from which it is operated iteratively.
I don't like it, i want to try and use an expandable vector of Uints.


Let's assume the numbers are simply 4 bits for simplification: 0000

SUM(+):
Lets have two numbers: 0111 & 0111, 3 bits each. This is te maximum value for a 3 bit sum and equals 1110 we use the 4th bit previously unused.
SO: With SUM, for there to be overflow there has to be at least one numbers that uses the most significant bit.
In function. We check if the first bit is used (with a simple & comparation) and if it is, check for overflow corrections.

How to handle overflow (in SUM)

We have n=1100 & m=0101.
We see n has the first bit used (n&0b1000 == True). 
Result is: n+m = 0001
We can simply check if sum < n, the overflowed result will always be lower than both numbers.
