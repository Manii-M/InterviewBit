/**
 *  this code is for the modinverse where we have given the modulo as prime number
 * so using fermats little theorem - a^p = 1 mod p
 * hence a^p-2 = a^-1 mod p
 * so we will have to find th a^-1 mod p which equivalent to a^p-2 mod p
 * 
*/
long long int fastpower(long long int base, int power, int mod)
{
    long long int result = 1;
    while (power > 0)
    {
        if (power % 2 == 1)
            result = (result * base) % mod;

        power = power >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int Solution::solve(int A, int B, int c)
{
    long long int fact[A + 1];
    fact[0] = 1, fact[1] = 1;
    for (int i = 2; i <= A; i++)
        fact[i] = (fact[i - 1] * i) % c;

    return int(fact[A] * fastpower((fact[A - B] * fact[B]) % c, c - 2, c) % c) % c;
}
