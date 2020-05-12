/*
Approach calculate GCD fo right and left array 
then check removing each element if gcd becomes 1 count that element.
Time Complexity will be O(3*nlog(max(Array)))
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
    int left_GCD[n], right_GCD[n];

    left_GCD[0] = A[0];
    right_GCD[n - 1] = A[n - 1];

    for (int i = 1; i < n; i++)
        left_GCD[i] = gcd(left_GCD[i - 1], A[i]);

    if (left_GCD[n - 1] == 1) //checking if GCD is already 1 then answer is zero
        return 0;

    int count = 0;

    for (int i = n - 2; i >= 0; i--)
        right_GCD[i] = gcd(right_GCD[i + 1], A[i]);

    for (int i = 0; i < n - 1; i++)
    {
        if (gcd(left_GCD[i - 1], right_GCD[i + 1]) == 1)
            count++;
        if (i == 0)
            if (right_GCD[i + 1] == 1)
                count++;
        if (i == n - 1)
            if (left_GCD[i - 1] == 1)
                count++;
    }

    if (count == 0) //not possible
        return -1;

    return count;
}
