vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    int i = 0, j = B.size() - 1, mini = INT_MAX;
    vector<int> answer;
    int l, r;
    while (i < A.size() && j >= 0)
    {
        int sum = A[i] + B[j];
        if (sum == C)
        {
            answer.push_back(A[i]);
            answer.push_back(B[j]);
            return answer;
        }

        int diff = abs(sum - C);

        if (diff < mini)
        {
            l = i;
            r = j;
            mini = diff;
        }
        else if (diff == mini)
        {
            if (i < l)
            {
                l = i;
                r = j;
            }
            else
            {
                if (i == l && j < r)
                {
                    l = i;
                    r = j;
                }
            }
        }
        if (sum > C)
        {
            j--;
        }
        else if (sum < C)
            i++;
    }
    answer.push_back(A[l]);
    answer.push_back(B[r]);
    return answer;
}
