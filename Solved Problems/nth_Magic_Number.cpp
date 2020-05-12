/*
Approach - similar to converting a binary to decimal 
it's a pattern
example - 101 = 1*5^3 + 0*5^2 + 1*5^1
*/


int Solution::solve(int A)
{
    int sum = 0;
    int c = 0;
    while (A)
    {
        int bit = A & 1;
        A = A >> 1;
        c++;
        if (bit)
        {
            sum += pow(5, c);
        }
    }
    return sum;
}