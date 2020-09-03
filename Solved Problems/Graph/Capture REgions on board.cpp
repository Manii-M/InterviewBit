/**
 * Capture Regions on Board
Problem Description

Given a 2-D board A of size N x M containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.



Problem Constraints
1 <= N, M <= 1000



Input Format
First and only argument is a N x M character matrix A.



Output Format
Make changes to the the input only as matrix is passed by reference.



Example Input
Input 1:

 A = [ 
       [X, X, X, X],
       [X, O, O, X],
       [X, X, O, X],
       [X, O, X, X] 
     ]
Input 2:

 A = [
       [X, O, O],
       [X, O, X],
       [O, O, O]
     ]


Example Output
Output 1:

 After running your function, the board should be:
 A = [
       [X, X, X, X],
       [X, X, X, X],
       [X, X, X, X],
       [X, O, X, X]
     ]
Output 2:

 After running your function, the board should be:
 A = [
       [X, O, O],
       [X, O, X],
       [O, O, O]
     ]


Example Explanation
Explanation 1:

 O in (4,2) is not surrounded by X from below.
Explanation 2:

 No O's are surrounded.
*/
int row[4] = {0, 0, -1, 1};
int col[4] = {-1, 1, 0, 0};
bool isvalid(int r, int c, int n, int m)
{
    if (r >= 0 && c >= 0 && r < n && c < m)
        return true;
    return false;
}
bool checkBoundary(int r, int c, int n, int m)
{
    if (r == 0 || r == n - 1 || c == 0 || c == m - 1)
        return true;
    return false;
}

void DFS(vector<vector<char>> &A, int start, int end, bool &checkB)
{

    if (checkBoundary(start, end, A.size(), A[0].size()) && checkB)
        checkB = false;
    A[start][end] = 'X';

    for (int i = 0; i < 4; i++)
    {
        int x = start + row[i];
        int y = end + col[i];
        if (isvalid(x, y, A.size(), A[0].size()) && A[x][y] == 'O')
        {
            DFS(A, x, y, checkB);
            if (!checkB)
                A[x][y] = 'C';
        }
    }
}

void Solution::solve(vector<vector<char>> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    // vector<vector<char> > answer(A);
    int n = A.size(), m = A[0].size();
    bool checkb = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            checkb = true;
            if (A[i][j] == 'O' && checkBoundary(i, j, n, m))
            {
                DFS(A, i, j, checkb);
                if (!checkb)
                    A[i][j] = 'C';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 'C')
                A[i][j] = 'O';
            else if (A[i][j] == 'O')
                A[i][j] = 'X';
        }
    }
}
