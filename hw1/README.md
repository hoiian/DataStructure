I use two ways to implement hw1,
It is known that the binomial coefficient means the combination.

hw1.c uses the formula (n,k) = n!/m!(n-m)! to implement,
the factorial is implemented by recursion.

hw1_1.c uses the recursicely computed by the formula:
(n,k) = (n-1,k) + (n-1,m-1)
