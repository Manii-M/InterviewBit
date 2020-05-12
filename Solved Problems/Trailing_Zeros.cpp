/*
Approach - every zero in factorial is result of 5*2 = 10 which will add 1 zero to the result.
so we have to count how many 5 will be there till N.

*/


int Solution::trailingZeroes(int A)
{
    int count = 0;

    while (n / 5)
    {
        count += n / 5;
        n /= 5;
    }

    return count;
}
