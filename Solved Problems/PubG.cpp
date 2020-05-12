/*
Calculate the GCD of the array from left to right 
when it comes to continues subtraction look in the way of GCD
*/


int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int Solution::solve(vector<int> &A)
{
    int n = A.size();
    for (int i = 1; i < n; i++)
    {
        A[i] = gcd(A[i - 1], A[i]);
    }
    return A[n - 1];
}
