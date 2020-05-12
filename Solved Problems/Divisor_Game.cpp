/*
LCM = A*B/GCD(A,B); lowest common multiple
if two numer's LCM divides a number, it will be divisble by both numbers.

*/

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int Solution::solve(int A, int B, int C)
{
    int toCheckFurther = 1, count = 0;
    long long lcm = B * C;
    lcm = lcm / gcd(B, C);
    while (A >= lcm * (toCheckFurther))
    {
        toCheckFurther++;
        count++;
    }

    return count;
}
