/**
 * Construct Roads
Problem Description

A country consist of N cities connected by N - 1 roads. King of that country want to construct maximum number of roads such that the new country formed remains bipartite country.

Bipartite country is a country, whose cities can be partitioned into 2 sets in such a way, that for each road (u, v) that belongs to the country, u and v belong to different sets. Also, there should be no multiple roads between two cities and no self loops.

Return the maximum number of roads king can construct. Since the answer could be large return answer % 109 + 7.

NOTE: All cities can be visited from any city.



Problem Constraints
1 <= A <= 105

1 <= B[i][0], B[i][1] <= N



Input Format
First argument is an integer A denoting the number of cities, N.

Second argument is a 2D array B of size (N-1) x 2 denoting the initial roads i.e. there is a road between cities B[i][0] and B[1][1] .



Output Format
Return an integer denoting the maximum number of roads king can construct.



Example Input
Input 1:

 A = 3
 B = [
       [1, 2]
       [1, 3]
     ]
Input 2:

 A = 5
 B = [
       [1, 3]
       [1, 4]
       [3, 2]
       [3, 5]
     ]


Example Output
Output 1:

 0
Output 2:

 2


Example Explanation
Explanation 1:

 We can't construct any new roads such that the country remains bipartite.
Explanation 2:

 We can add two roads between cities (1, 2) and (1, 5).
*/
int Solution::solve(int A, vector<vector<int>> &B)
{
    vector<vector<int>> adjlist(A);
    vector<int> color(A, -1);
    int mod = 1000000007;

    for (int i = 0; i < B.size(); i++)
    {
        adjlist[B[i][0] - 1].push_back(B[i][1] - 1);
        adjlist[B[i][1] - 1].push_back(B[i][0] - 1);
    }

    queue<int> q;
    q.push(0);
    color[0] = 0; //red color;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        vector<int> adj = adjlist[v];
        for (int i = 0; i < adj.size(); i++)
        {
            if (color[adj[i]] == -1)
            {
                color[adj[i]] = 1 - color[v];
                q.push(adj[i]);
            }
        }
    }

    int red = 0, green = 0;

    for (int i = 0; i < A; i++)
    {
        if (color[i] == 0)
            red++;
        else if (color[i] == 1)
            green++;
    }

    long long int answer = ((long long int)red * green) % mod;
    int n = B.size() % mod;

    if (answer >= n)
        return (answer - n) % mod;
    return 0;
}
