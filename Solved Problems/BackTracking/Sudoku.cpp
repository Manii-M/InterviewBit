bool isSafe(vector<vector<char>> &A, int row, int col, int n, char current_char)
{
    if (!(row >= 0 && row < n && col >= 0 && col < n))
        return false;
    //check the entire row is not having the current_char
    for (int colm = 0; colm < n; colm++)
        if (A[row][colm] == current_char)
            return false;

    //check the entire column is not having the current_char
    for (int roww = 0; roww < n; roww++)
        if (A[roww][col] == current_char)
            return false;

    //check if the 3x3 box has no clashes
    int sqroot = sqrt(n);
    int boxRowStart = row - row % sqroot; //start of 3x3 box row index
    int boxColStart = col - col % sqroot; // start of 3x3 box col index

    for (int i = boxRowStart; i < boxRowStart + sqroot; i++)
        for (int j = boxColStart; j < boxColStart + sqroot; j++)
            if (A[i][j] == current_char)
                return false;

    return true;
}

bool solve_Sudoku(vector<vector<char>> &A, int row, int col, int n)
{
    bool emptyCell = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (A[i][j] == '.')
            {
                row = i;
                col = j;
                emptyCell = true;
                break;
            }
        if (emptyCell)
            break;
    }
    if (!emptyCell)
        return true;

    for (char num = '1'; num <= '9'; num++)
    {
        if (isSafe(A, row, col, n, num))
        {
            A[row][col] = num;
            if (solve_Sudoku(A, row, col + 1, n))
                return true;
            A[row][col] = '.';
        }
    }

    return false;
}

void Solution::solveSudoku(vector<vector<char>> &A)
{
    bool answer = solve_Sudoku(A, 0, 0, A.size());
}
