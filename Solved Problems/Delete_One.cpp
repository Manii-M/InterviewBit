/*
Approach to calculate till each element GCD  from left and from right.
and delete element 1 by 1 and refer to left gcd array for the gcd of the left side till that element 
and right gcd array till for right side gcd in the array. and take maximum that will be mximum gcd.
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

    for (int i = n - 2; i >= 0; i--)
        right_GCD[i] = gcd(right_GCD[i + 1], A[i]);

    int maxGCD = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            if (right_GCD[i + 1] > maxGCD) //if first element there is nothing on the left side so cosidering only right
                maxGCD = right_GCD[i + 1];

        if (i == n - 1) //if last element there is nothing on the right side so cosidering only left
            if (left_GCD[i - 1] > maxGCD)
                maxGCD = left_GCD[i - 1];

        if (i > 0 && i < n - 1) // in between elements
        {
            int newGCD = gcd(left_GCD[i - 1], right_GCD[i + 1]); //left side gcd and right_GCD side gcd without the ith element
            if (newGCD > maxGCD)
                maxGCD = newGCD;
        }
    }

    return maxGCD;
}