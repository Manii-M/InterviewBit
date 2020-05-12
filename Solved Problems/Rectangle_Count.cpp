/**
 * same two pointer approach will work here
*/
int Solution::solve(vector<int> &A, int B)
{
    long long int count = 0;
    int i = 0, j = A.size() - 1, mod = 1000000007;
    while (i <= j)
    {
        long long int area = (long long int)A[i] * A[j];
        if (area >= B)
            j--;
        else if (area < B)
        {
            count = (count + ((2 * (j - i + 1)) % mod - 1)) % mod;
            i++;
        }
    }
    return (int)count;
}
