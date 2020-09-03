// Another BFS
// Problem Description

// Given a weighted undirected graph having A nodes, a source node C and destination node D.

// Find the shortest distance from C to D and if it is impossible to reach node D from C then return -1.

// You are expected to do it in Time Complexity of O(A + M).

// Note:

// There are no self-loops in the graph.

// No multiple edges between two pair of vertices.

// The graph may or may not be connected.

// Nodes are Numbered from 0 to A-1.

// Your solution will run on multiple testcases. If you are using global variables make sure to clear them.

// Problem Constraints
// 1 <= A <= 105

// 0 <= B[i][0], B[i][1] < A

// 1 <= B[i][2] <= 2

// 0 <= C < A

// 0 <= D < A

// Input Format
// The first argument given is an integer A, representing the number of nodes.

// The second argument given is the matrix B, where B[i][0] and B[i][1] are connected through an edge of weight B[i][2].

// The third argument given is an integer C, representing the source node.

// The fourth argument is an integer D, representing the destination node.

// Note: B[i][2] will be either 1 or 2.

// Output Format
// Return the shortest distance from C to D. If it is impossible to reach node D from C then return -1.

// Example Input
// Input 1:

// A = 6
// B = [   [2, 5, 1]
//         [1, 3, 1]
//         [0, 5, 2]
//         [0, 2, 2]
//         [1, 4, 1]
//         [0, 1, 1] ]
// C = 3
// D = 2
// Input 2:

// A = 2
// B = [   [0, 1, 1]
//     ]
// C = 0
// D = 1

// Example Output
// Output 1:

//  4
// Output 2:

//  1

// Example Explanation
// Explanation 1:

// The path to be followed will be:
//     3 -> 1 (Edge weight : 1)
//     1 -> 0 (Edge weight : 1)
//     0 -> 2 (Edge weight : 2)
// Total length of path = 1 + 1 + 2 = 4.
// Explanation 2:

//  Path will be 0-> 1.
int Solution::solve(vector<int> &A, const int B, const int C)
{
    if (B == C)
        return 1;
    int n = A.size();
    vector<vector<int>> list(n);
    for (int i = 1; i < n; i++)
        list[A[i] - 1].push_back(i);
    queue<int> q;
    q.push(C - 1);
    vector<bool> visited(n, false);
    visited[C - 1] = true;

    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        vector<int> v = list[top];
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == B - 1)
                return 1;
            if (!visited[v[i]])
            {
                visited[v[i]] = true;
                q.push(v[i]);
            }
        }
    }
    return 0;
}
struct node
{
    int x, weight, dist;
    node(int i, int w, int d) : x(i), weight(w), dist(d){};
};

int Solution::solve(int A, vector<vector<int>> &B, int C, int D)
{
    if (C == D)
        return 0;
    vector<vector<node>> list(A);

    for (int i = 0; i < B.size(); i++)
    {
        list[B[i][0]].push_back(node(B[i][1], B[i][2], 0));
        list[B[i][1]].push_back(node(B[i][0], B[i][2], 0));
    }

    queue<node> q;
    vector<bool> visited(A, false);
    q.push(node(C, 0, 0));

    while (!q.empty())
    {
        struct node top = q.front();
        q.pop();

        vector<node> p = list[top.x];

        if (top.weight == 2)
        {
            q.push(node(top.x, 1, top.dist + 1));
            continue;
        }

        if (top.x == D)
            return top.dist;

        visited[top.x] = true;

        for (int i = 0; i < p.size(); i++)
        {
            struct node p1 = p[i];
            if (!visited[p1.x])
                q.push(node(p1.x, p1.weight, top.dist + 1));
        }
    }
    return -1;
}
