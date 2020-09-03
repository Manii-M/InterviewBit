/**
 * Dijsktra
Problem Description

Given a weighted undirected graph having A nodes and M weighted edges, and a source node C.

You have to find an integer array D of size A such that:

=> D[i] : Shortest distance form the C node to node i.

=> If node i is not reachable from C then -1.

Note:

There are no self-loops in the graph.

No multiple edges between two pair of vertices.

The graph may or may not be connected.

Nodes are numbered from 0 to A-1.

Your solution will run on multiple testcases. If you are using global variables make sure to clear them.



Problem Constraints
1 <= A <= 1e5

0 <= B[i][0],B[i][1] < A

0 <= B[i][2] <= 1e3

0 <= C < A



Input Format
The first argument given is an integer A, representing the number of nodes.

The second argument given is the matrix B of size M x 3, where nodes B[i][0] and B[i][1] are connected with an edge of weight B[i][2].

The third argument given is an integer C.



Output Format
Return the integer array D.



Example Input
Input 1:

A = 6
B = [   [0, 4, 9]
        [3, 4, 6] 
        [1, 2, 1] 
        [2, 5, 1] 
        [2, 4, 5] 
        [0, 3, 7] 
        [0, 1, 1] 
        [4, 5, 7] 
        [0, 5, 1] ] 
C = 4
Input 2:

A = 5
B = [   [0, 3, 4]
        [2, 3, 3] 
        [0, 1, 9] 
        [3, 4, 10] 
        [1, 3, 8]  ] 
C = 4


Example Output
Output 1:

D = [7, 6, 5, 6, 0, 6]
Output 2:

D = [14, 18, 13, 10, 0]


Example Explanation
Explanation 1:

 All Paths can be considered from the node C to get shortest path
Explanation 2:

 All Paths can be considered from the node C to get shortest path
*/
struct node
{
    int v, w;
    node(int i, int wi) : v(i), w(wi) {}
};

bool operator<(node n1, node n2)
{
    return n1.w > n2.w;
}
vector<int> Solution::solve(int A, vector<vector<int>> &B, int C)
{
    priority_queue<node> pq;
    vector<node> list[A];
    for (int i = 0; i < B.size(); i++)
    {
        list[B[i][0]].push_back(node(B[i][1], B[i][2]));
        list[B[i][1]].push_back(node(B[i][0], B[i][2]));
    }
    vector<int> answer(A, -1);
    vector<bool> visited(A, false);
    pq.push(node(C, 0));

    while (!pq.empty())
    {
        node top = pq.top();
        pq.pop();

        if (visited[top.v])
            continue;
        visited[top.v] = true;
        answer[top.v] = top.w;
        vector<node> adj = list[top.v];
        for (int i = 0; i < adj.size(); i++)
        {
            if (!visited[adj[i].v])
                pq.push(node(adj[i].v, adj[i].w + top.w));
        }
    }
    return answer;
}
