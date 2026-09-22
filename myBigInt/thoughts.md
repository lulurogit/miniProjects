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


SUB(-)
Thinking about it this was a little trickier that i thought it would be. I'ts not that hard though.
Let's imagine 2 digit integers and the next subtraction: 1010-180.

We would analize from lower to higher -> first 10-80 then 10-1(and carry logic).
I cant just add 100 to the 10 because it would just overflow so. If the first number is lower than the subtracted one. We have to save the difference (80-10 = 70). And then "bring" the carry from the first number by putting it to UINT_MAX (this means we have to subtract one from the difference, since UINT_MAX here is 1 less than the carry we brought from the higher number -> 70-1 = 69. Maybe i can save the -1 but subtracting directly from 0 and forcing it around, but it seems sketchy)

Then just subtract the difference to the new UINT_MAX we established (and manage the carry logic).

1010-80:
10-80 = (70)   
"100"-70 = 30
10(-1)-1=8
Result: 8 30   CORRECT

Also important. As to maintain the carry mechanisms the same. We always substract bigger number from smaller, and invert signs whenever necessary.
