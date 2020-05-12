/*
GCD _ Greatest Common Divisors
A = 4 , B = 8
GCD of A B is 4 which is the greatest number which divides both A & B.

fact 1 - {GCD of 12 0 is 12 because max number divides zero is 12 but every number divides zero}

fact 2 - {GCD(-5,0) = 5 ecause 5 is the greatest divisor}

we can drive GCD(A, 0) = |A| when A!=0, if A=0 it will undefined as zero is divisible by every number.

GCD(A, 1) = 1 , as 1 is the greatest number it can not be greater then 1 for both numbers.

finding GCD is taking here log(max(A, B)) time.
*/

int Solution::gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
