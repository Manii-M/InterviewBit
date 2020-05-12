int binary_search(vector<int> row, int start, int end, int number)
{

    if (start <= end)
    {

        int mid = start + (end - start) / 2;

        if (row[mid] == number)
            return mid;

        if (row[mid] > number)
            return binary_search(row, start, mid - 1, number);

        return binary_search(row, mid + 1, end, number);
    }
    return -1;
}

int Solution::solve(vector<vector<int>> &A, int B)
{

    int maxi = 0, ans = INT_MAX;

    for (int i = 0; i < A.size(); i++)
    {

        int found_at = binary_search(A[i], 0, A[i].size() - 1, B);
        if (found_at >= 0)
        {

            maxi = ((i + 1) * 1009) + (found_at + 1);
            ans = ans > maxi ? maxi : ans;
        }
    }
    return ans == INT_MAX ? -1 : ans;
}
