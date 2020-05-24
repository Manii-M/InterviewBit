/**
 * Question - https://www.interviewbit.com/problems/power-of-two-integers/
 * Solution Approach - Lets look at the number of valid possibilities for A^B.


For B = 2, number of possibilities = sqrt(INT_MAX) = sqrt(2^31 - 1) < 2^16.
For B = 3, number of possibilities = INT_MAX**1/3 < 2^11
For B = 4, number of possibilities = INT_MAX**1/4 < 2^8
.
.
.
For B = 32, number of possibilities = 0 ( Not considering 1 as its considered in the first case, and 2^32 exceeds INT_MAX ). 

So, the total number of possibilities are less than 10^5.

Now, we just need to iterate on these possibilities and see if we find X = A^B.

Take extra care to make sure there are no overflows.
*/
public
class Solution
{
public
    int isPower(int A)
    {
        if (A == 1)
            return 1;
        for (int i = 2; i * i <= A; i++)
        {
            int n = A;
            while (n >= 1 && n % i == 0)
                n /= i;

            if (n == 1)
                return 1;
        }
        return 0;
    }
}
