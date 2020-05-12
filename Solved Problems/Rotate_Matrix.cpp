/*
the logic behind is to see the pattern when we are rotating the element
every (i,j) will react to (n-j,i).
so keep swapping the elements in the way untill all are not at their correct place (in a circular way)
*/
void Solution::solve(vector<vector<int>> &a)
{
    int n = a.size();
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            int swap = a[i][j];
            a[i][j] = a[n - 1 - j][i];
            a[n - 1 - j][i] = a[n - 1 - i][n - 1 - j];
            a[n - 1 - i][n - 1 - j] = a[j][n - 1 - i];
            a[j][n - 1 - i] = swap;
        }
    }
}
