/**
 * Approah - calculate the prefix sum of each sub-matrix  in the matrix
 * row wise prefix sum then column wise prefix sum
 * sum of the query sub-matrix will be - sum[B][R]-sum[T-1][R]-sum[B][L-1]+sum[T-1][L-1]
*/

vector<int> Solution::solve(vector<vector<int>> &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E)
{
    vector<int> v;
    int pre = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 1; j < A[i].size(); j++)
        {
            pre = (A[i][j] + A[i][j - 1]);
            A[i][j] = pre % 1000000007;
        }
    }

    for (int j = 0; j < A[0].size(); j++)
    {
        for (int i = 1; i < A.size(); i++)
        {
            pre = (A[i][j] + A[i - 1][j]);
            A[i][j] = pre % 1000000007;
        }
    }

    int sum = 0;
    for (int i = 0; i < B.size(); i++)
    {

        int top = B[i] - 1, left = C[i] - 1, bottom = D[i] - 1, right = E[i] - 1;

        sum = 0;

        if (bottom >= 0 && right >= 0)
            sum = A[bottom][right];

        if (bottom >= 0 && left - 1 >= 0)
            sum = (sum - A[bottom][left - 1]);

        if (right >= 0 && top - 1 >= 0)
            sum = (sum - A[top - 1][right]);

        if (left - 1 >= 0 && top - 1 >= 0)
            sum = (sum + A[top - 1][left - 1]) % 1000000007;
        if (sum >= 0)
            v.push_back(sum);
        else
            v.push_back(1000000007 + sum);
    }
    return v;
}
