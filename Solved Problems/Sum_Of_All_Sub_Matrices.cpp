//for each element how many submatrices it can have.
//which means combination of TOPLEFT and BOTTOMRIGHT
//for each element how can i choose TOPLEFT so the element will be part of it
// for each element how can i choose  BOTTOMRIGHT so the element will be part of it
//poosible TOPLEFT * BOTTOMRIGHT = number of possible submatrices that will contain the element.

int Solution::solve(vector<vector<int>> &A)
{
    int n = A.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int Count_Top_Left = (i + 1) * (j + 1);
            int Count_Bottom_Right = (n - i) * (n - j);
            int total_possible_submatrices = Count_Top_Left * Count_Bottom_Right;
            sum += total_possible_submatrices * A[i][j];
        }
    }
    return sum;
}
