/**
 * Black Shapes
Problem Description

Given character matrix A of O's and X's, where O = white, X = black.

Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)



Problem Constraints
1 <= |A|,|A[0]| <= 1000

A[i][j] = 'X' or 'O'



Input Format
The First and only argument is character matrix A.



Output Format
Return a single integer denoting number of black shapes.



Example Input
Input 1:

 A = [ [X, X, X], [X, X, X], [X, X, X] ]
Input 2:

 A = [ [X, O], [O, X] ]


Example Output
Output 1:

 1
Output 2:

 2


Example Explanation
Explanation 1:

 All X's belong to single shapes
Explanation 2:

 Both X's belong to different shapes
*/
bool isvalid(int row, int col, int n, int m)
{
    if (row >= 0 && col >= 0 && row < n && col < m)
        return true;
    return false;
}
void DFSUtil(int r, int c, vector<string> &A)
{
    int row[4] = {0, 0, -1, 1};
    int col[4] = {-1, 1, 0, 0};
    A[r][c] = 'O';
    for (int i = 0; i < 4; i++)
    {
        int re = r + row[i], ce = c + col[i];
        if (isvalid(re, ce, A.size(), A[0].size()) && A[re][ce] == 'X')
        {
            DFSUtil(re, ce, A);
        }
    }
}
void DFS(vector<pair<int, int>> v, int &count, vector<string> &A)
{

    // vector<bool> visited(v.size(),false);
    for (int i = 0; i < v.size(); i++)
    {
        pair<int, int> p = v[i];
        if (A[p.first][p.second] == 'X')
        {
            DFSUtil(p.first, p.second, A);
            count++;
        }
    }
}
int Solution::black(vector<string> &A)
{
    int n = A.size(), m = A[0].size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        string str = A[i];
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == 'X')
            {
                v.push_back({i, j});
            }
            // cout<<a[i][j]<<" ";
        }
        // cout<<endl;
    }
    int count = 0;
    DFS(v, count, A);
    return count;
}
