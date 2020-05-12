/**
 * Approach 1 - brute force is to take all subarray and see all the elements are unique or not
 * TC - O(n^2) and to check also O(n) 
 * Approach 2 - we can have a frequency array.
 * and based on that we'll keep counting the subarrays which has freq == 1
 * as we encounter the element freq>1 we'll keep decrementing the freq and until for that element freq doesn't come down to 1
 * TC - O(n) as we are traversing the array only once
 * SC - O(n) for frequency array
*/
int Solution::solve(vector<int> &A)
{
    map<int, int> m;
    long long int l = 0, r = 0, answer = 0, mod = 1000000007;
    while (l <= r && r < A.size())
    {
        m[A[r]]++;
        while (m[A[r]] > 1)
        {
            m[A[l]]--;
            l++;
        }
        answer += r - l + 1;
        if (answer > mod)
            answer -= mod;
        r++;
    }
    return (int)(answer % mod);
}
