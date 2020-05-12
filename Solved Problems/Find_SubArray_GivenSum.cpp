/**
 * Approach is to use the prefix sum then this problem is similar to the A[i]-A[j]=k problem 
 * only edge case here is if the sum is equal to continuous numbers which we are handling separately as prefix wil give range only.
 * TC- O(n)
 * SC - O(n)
*/
vector<int> Solution::solve(vector<int> &A, int B)
{
    long long int prefix_sum[A.size()];
    vector<int> v;
    for (int i = 0; i < A.size(); i++)
    {
        if (i == 0)
            prefix_sum[i] = A[i];
        else
            prefix_sum[i] = prefix_sum[i - 1] + A[i];
    }

    int i = 0, j = 1;
    if (prefix_sum[i] == B)
    {
        v.push_back(A[i]);
        return v;
    }

    while (i < j && j < A.size())
    {

        if (prefix_sum[j] - prefix_sum[i] > B)
        {
            i++;
            if (i == j)
                j++;
        }
        if (prefix_sum[j] - prefix_sum[i] < B)
        {
            j++;
        }
        if (prefix_sum[j] - prefix_sum[i] == B)
        {

            int start = i + 1, end = j;

            while (start <= end)
            {
                v.push_back(A[start]);
                start++;
            }
            return v;
        }

        if (prefix_sum[j] == B)
        {
            int start = 0, end = j;

            while (start <= end)
            {
                v.push_back(A[start]);
                start++;
            }
            return v;
        }

        if (prefix_sum[i] == B)
        {
            int start = 0, end = i;

            while (start <= end)
            {
                v.push_back(A[start]);
                start++;
            }
            return v;
        }
    }
    v.push_back(-1);
    return v;
}

/**
 * This approach is taking O(1) time.
 * 
*/
vector<int> Solution::solve(vector<int> &A, int B)
{
    int i = 0;
    vector<int> answer;
    while (i < A.size())
    {
        long long int j = i, sum = 0;
        while (j < A.size() && i <= j)
        {
            if (A[j] == B)
            {
                answer.push_back(B);
                return answer;
            }
            if (sum < B)
            {
                sum += A[j];
                j++;
            }
            else if (sum > B)
            {
                sum -= A[i];
                i++;
            }
            else if (sum == B)
            {
                int start = i, end = j - 1;
                while (start <= end)
                {
                    answer.push_back(A[start]);
                    start++;
                }
                return answer;
            }
        }
        i = j;
    }
    answer.push_back(-1);
    return answer;
}
