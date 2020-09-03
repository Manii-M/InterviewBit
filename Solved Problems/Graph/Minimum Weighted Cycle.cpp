/**
 * Minimum Weighted Cycle
Problem Description

Given an integer A, representing number of vertices in a graph.

Also you are given a matrix of integers B of size N x 3 where N represents number of Edges in a Graph and Triplet (B[i][0], B[i][1], B[i][2]) implies there is an undirected edge between B[i][0] and B[i][1] and weight of that edge is

B[i][2].

Find and return the weight of minimum weighted cycle and if there is no cycle return -1 instead.

NOTE: Graph may contain multiple edges and self loops.



Problem Constraints
1 <= A <= 1000

1 <= B[i][0], B[i][1] <= A

1 <= B[i][2] <= 100000



Input Format
The first argument given is the integer A.

The second argument given is the integer matrix B.



Output Format
Return the weight of minimum weighted cycle and if there is no cycle return -1 instead.



Example Input
Input 1:

 A = 4
 B = [  [1 ,2 ,2]
        [2 ,3 ,3]
        [3 ,4 ,1]
        [4 ,1 ,4]
        [1 ,3 ,15]  ]
Input 2:

 A = 3
 B = [  [1 ,2 ,2]
        [2 ,3 ,3]  ]


Example Output
Output 1:

 10 
Output 2:

 -1


Example Explanation
Explanation 1:

 Given graph forms 3 cycles
 1. 1 ---> 2 ---> 3 ---> 4 ---> 1 weight = 10
 2. 1 ---> 2 ---> 3 ---> 1 weight = 20
 3. 1 ---> 3---> 4 ---> 1 weight = 20
 so answer would be 10.
Explanation 2:

 Given graph forms 0 cycles so return -1.
*/
struct node
{
    int x, w;
    node(int i, int we) : x(i), w(we) {}
};
bool operator<(node n1, node n2)
{
    return n1.w > n2.w;
}
int Solution::solve(int A, vector<vector<int>> &B)
{

    vector<node> list[A];
    for (int i = 0; i < B.size(); i++)
    {
        list[B[i][0] - 1].push_back(node(B[i][1] - 1, B[i][2]));
        list[B[i][1] - 1].push_back(node(B[i][0] - 1, B[i][2]));
    }

    int answer = INT_MAX;
    for (int i = 0; i < B.size(); i++)
    {
        int u = B[i][0] - 1, v = B[i][1] - 1;
        priority_queue<node> pq; //dijkshtra algoritham
        vector<bool> visited(A, false);
        pq.push(node(u, 0));
        while (!pq.empty())
        {
            node top = pq.top();
            pq.pop();
            if (visited[top.x])
                continue;
            visited[top.x] = true;
            if (visited[v])
            {
                if (answer > top.w + B[i][2])
                    answer = top.w + B[i][2];
                break;
            }

            vector<node> adj = list[top.x];

            for (int j = 0; j < adj.size(); j++)
            {
                //  cout<<top.x<<endl;
                if ((top.x == u && adj[j].x == v) || (adj[j].x == u && top.x == v))
                {
                    //  cout<<u<<" "<<v<<endl;
                    continue;
                }
                if (!visited[adj[j].x])
                    pq.push(node(adj[j].x, top.w + adj[j].w));
            }
        }
    }

    if (answer == INT_MAX)
        return -1;
    return answer;
}
