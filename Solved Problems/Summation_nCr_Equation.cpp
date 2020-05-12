/**
 * Approach here is 
 * The Binomial Theorem

The Binomial Theorem states that, where n is a positive integer:

(a + b)n = an + (nC1)an-1b + (nC2)an-2b2 + … + (nCn-1)abn-1 + bn
using this a = 1 and putting b =x differentiate the equation and get the equivalent expression to evaluate 
*/
long long int fastPower(long long int base, int power, int mod)
{
    long long int result = 1;
    while (power > 0)
    {
        if (power & 1 == 1)
            result = (result * base) % mod;
        power >>= 1;
        base = (base * base) % mod;
    }

    return result % mod;
}

int Solution::solve(int A)
{
    int mod = 1000000007;
    return int((A * (A - 1)) % mod * fastPower((long long int)3, A - 2, mod) % mod) % mod;
}
