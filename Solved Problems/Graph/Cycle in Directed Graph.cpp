/**
 * Cycle in Directed Graph
Problem Description

Given an directed graph having A nodes. A matrix B of size M x 2 is given which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].

Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.

NOTE:

The cycle must contain atleast two nodes.
There are no self-loops in the graph.
There are no multiple edges between two nodes.
The graph may or may not be connected.
Nodes are numbered from 1 to A.
Your solution will run on multiple test cases. If you are using global variables make sure to clear them.


Problem Constraints
2 <= A <= 105

1 <= M <= min(200000,A*(A-1))

1 <= B[i][0], B[i][1] <= A



Input Format
The first argument given is an integer A representing the number of nodes in the graph.

The second argument given a matrix B of size M x 2 which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].



Output Format
Return 1 if cycle is present else return 0.



Example Input
Input 1:

 A = 5
 B = [  [1, 2] 
        [4, 1] 
        [2, 4] 
        [3, 4] 
        [5, 2] 
        [1, 3] ]
Input 2:

 A = 5
 B = [  [1, 2]
        [2, 3] 
        [3, 4] 
        [4, 5] ]


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 The given graph contain cycle 1 -> 3 -> 4 -> 1 or the cycle 1 -> 2 -> 4 -> 1
Explanation 2:

 The given graph doesn't contain any cycle.
*/
#define MAXN 100005
#define BLACK 0
#define BLUE 1
#define GREY 2
vector<int> g[MAXN];
void check_cycle(int u, int visited[], bool &f)
{
    visited[u] = BLUE;
    for (auto v : g[u])
    {
        if (visited[v] == BLACK)
        {
            check_cycle(v, visited, f);
        }
        else if (visited[v] == BLUE)
        {
            //cycle found
            f = true;
        }
    }
    visited[u] = GREY;
}

int Solution::solve(int N, vector<vector<int>> &B)
{
    bool f = false;
    int visited[MAXN] = {0};
    for (int i = 1; i <= N; i++)
    {
        g[i].clear();
    }
    for (int i = 0; i < B.size(); i++)
    {
        g[B[i][0]].push_back(B[i][1]);
    }
    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == BLACK)
        {
            check_cycle(i, visited, f);
            if (f)
            {
                break;
            }
        }
    }
    return f;
}