/**
 * Approach is to get the 3 pointers each in 2 of the array an keep moving them based on the minimum element we will get from the array.
*/
int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int i = 0, j = 0, k = 0, answer = INT_MAX;
    while (i < A.size() && j < B.size() && k < C.size())
    {
        int mini = min({A[i], B[j], C[k]});
        int maxi = max({abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])});
        answer = min(answer, maxi);
        if (mini == A[i])
            i++;
        else if (mini == B[j])
            j++;
        else if (mini == C[k])
            k++;
    }
    return answer;
}
