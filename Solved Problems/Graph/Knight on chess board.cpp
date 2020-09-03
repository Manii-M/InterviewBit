/**
 * Knight On Chess Board
Problem Description

Given any source point, (C, D) and destination point, (E, F) on a chess board of size A x B, we need to find whether Knight can move to the destination or not.


The above figure details the movements for a knight ( 8 possibilities ).

If yes, then what would be the minimum number of steps for the knight to move to the said point. If knight can not move from the source point to the destination point, then return -1.

NOTE: A knight cannot go out of the board.



Problem Constraints
1 <= A, B <= 500



Input Format
The first argument of input contains an integer A.
The second argument of input contains an integer B.
The third argument of input contains an integer C.
The fourth argument of input contains an integer D.
The fifth argument of input contains an integer E.
The sixth argument of input contains an integer F.



Output Format
If it is possible to reach the destination point, return the minimum number of moves.
Else return -1.



Example Input
Input 1:

 A = 8
 B = 8
 C = 1
 D = 1
 E = 8
 F = 8
Input 2:

 A = 2
 B = 4
 C = 2
 D = 1
 E = 4
 F = 4


Example Output
Output 1:

 6
Output 2:

 -1


Example Explanation
Explanation 1:

 The size of the chessboard is 8x8, the knight is initially at (1, 1) and the knight wants to reach position (8, 8).
 The minimum number of moves required for this is 6.
Explanation 2:

 It is not possible to move knight to position (4, 4) from (2, 1)
*/
struct node
{
    int x, y, dist;
    node(int i, int j, int d) : x(i), y(j), dist(d){};
};
bool isvalid(int r, int c, int n, int m)
{
    if (r >= 0 && c >= 0 && r < n && c < m)
        return true;
    return false;
}
int Solution::knight(int A, int B, int C, int D, int E, int F)
{
    if (C == E && D == F)
        return 0;
    vector<vector<int>> board(A, vector<int>(B, 0));
    int row[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
    int col[8] = {-2, -2, -1, 1, 2, 2, 1, -1};

    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < B; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                int r = i + row[k];
                int c = j + col[k];
                if (isvalid(r, c, A, B))
                    board[r][c] = 1;
            }
        }
    }

    queue<node> q;
    q.push(node(C - 1, D - 1, 0));
    board[C - 1][D - 1] = 0;

    while (!q.empty())
    {
        struct node top = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int r = top.x + row[i];
            int c = top.y + col[i];
            if (r == E - 1 && c == F - 1)
                return top.dist + 1;
            if (isvalid(r, c, A, B) && board[r][c] == 1)
            {
                board[r][c] = 0;
                q.push(node(r, c, top.dist + 1));
            }
        }
    }

    return -1;
}
