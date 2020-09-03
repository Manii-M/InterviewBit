/**
 * Valid Path
Problem Description

There is a rectangle with left bottom as (0, 0) and right up as (x, y).

There are N circles such that their centers are inside the rectangle.

Radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching any circle.

Note : We can move from any cell to any of its 8 adjecent neighbours and we cannot move outside the boundary of the rectangle at any point of time.



Problem Constraints
0 <= x , y, R <= 100

1 <= N <= 1000

Center of each circle would lie within the grid



Input Format
1st argument given is an Integer x , denoted by A in input.

2nd argument given is an Integer y, denoted by B in input.

3rd argument given is an Integer N, number of circles, denoted by C in input.

4th argument given is an Integer R, radius of each circle, denoted by D in input.

5th argument given is an Array A of size N, denoted by E in input, where A[i] = x cordinate of ith circle

6th argument given is an Array B of size N, denoted by F in input, where B[i] = y cordinate of ith circle



Output Format
Return YES or NO depending on weather it is possible to reach cell (x,y) or not starting from (0,0).



Example Input
Input 1:

 x = 2
 y = 3
 N = 1
 R = 1
 A = [2]
 B = [3]
Input 2:

 x = 1
 y = 1
 N = 1
 R = 1
 A = [1]
 B = [1]


Example Output
Output 1:

 NO
Output 2:

 NO


Example Explanation
Explanation 1:

 There is NO valid path in this case
Explanation 2:

 There is NO valid path in this case
*/

int row[8] = {1, -1, 0, 0, 0, 1, 1, -1};
int col[8] = {0, 0, -1, 1, -1, -1, 1, 1};
struct node
{
    int i, j;
    node(int x, int y)
    {
        i = x;
        j = y;
    }
};

bool isvalid(int row, int col, int n, int m)
{
    if (row >= 0 && col >= 0 && row <= n && col <= m)
        return true;
    return false;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F)
{
    vector<vector<int>> rect(A + 1, vector<int>(B + 1, 0));
    queue<node> q;

    for (int i = 0; i <= A; i++)
    {
        for (int j = 0; j <= B; j++)
        {
            for (int k = 0; k < C; k++)
            {
                if (sqrt(pow(E[k] - i, 2) + pow(F[k] - j, 2)) <= D)
                    rect[i][j] = 1;
            }
        }
    }
    if (rect[0][0] == 1)
        return "NO";

    q.push(node(0, 0));
    while (!q.empty())
    {
        struct node top = q.front();
        q.pop();

        for (int k = 0; k < 8; k++)
        {
            int r = top.i + row[k];
            int c = top.j + col[k];

            if (isvalid(r, c, A, B) && rect[r][c] == 0)
            {
                if (r == A && c == B)
                    return "YES";
                rect[r][c] = 1;
                q.push(node(r, c));
            }
        }
    }
    return "NO";
}
