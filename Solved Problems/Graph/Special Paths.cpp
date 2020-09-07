/**
 * Special path
Problem Description

Given a graph with N nodes numbered 1 to N and M weighted edges. Given a binary array A of size N. A[i] = 1 if the ith node is special else 0.

Find the minimum distance of the special path between the 1st and the Nth node. Distance between two nodes is defined as the sum of the weight of edges in the path.

A special path is a path which visits alteast C non-special nodes and atleast D special nodes.

NOTE: A node or edge can occur multiple times in a special path. If no such path exists return -1.



Problem Constraints
1 <= N, M <= 10000
0 <= A[i] <= 1
1 <= B[i][0], B[i][1] <= N
1 <= B[i][2] <= 100000
0 <= C, D <= 10



Input Format
First argument is an integer array A of size N
Second argument is a 2-D integer array B of size M*3 denoting edges. B[i][0] and B[i][1] are connected by ith edge with weight B[i][2]
Third argument is an integer C
Fourth argument is an integer D



Output Format
Return an integer denoting the minimum distance of the special path. Return -1 if no such path exists.



Example Input
Input 1:

A = [0, 1, 0]
B = [ [1, 2, 3], [2, 3, 5] ] 
C = 2
D = 3
Input 2:

A = [1, 1]
B = [ [1, 2, 1] ]
C = 1
D = 1


Example Output
Output 1:

 20
Output 2:

 -1


Example Explanation
Explanation 1:

 Minimum distance of the special path is 20 ( 1 -> 2 -> 1 -> 2 -> 1 -> 2 -> 3).
 Number of visits of non-special nodes = 4 (1, 1, 1, 3)
 Number of visits of special nodes = 3 (2, 2, 2)
Explanation 2:

 Cannot be achieved.
*/
struct nodes
{
    int node, spcl, n_spcl, weight;
    nodes(int no, int c, int d, int wt) : node(no), spcl(c), n_spcl(d), weight(wt)
    {
    }
};
bool operator<(nodes n1, nodes n2)
{
    return n1.weight > n2.weight;
}
struct newnode
{
    int n, speciality, weight;
    newnode(int nth, int sp, int wit) : n(nth), speciality(sp), weight(wit) {}
};

int Solution::solve(vector<int> &A, vector<vector<int>> &B, int C, int D)
{
    int n = A.size();
    vector<newnode> list[n];
    for (int i = 0; i < B.size(); i++) //making adjacency list
    {
        list[B[i][0] - 1].push_back(newnode(B[i][1] - 1, A[B[i][1] - 1], B[i][2]));
        list[B[i][1] - 1].push_back(newnode(B[i][0] - 1, A[B[i][0] - 1], B[i][2]));
    }

    priority_queue<nodes> q;
    int dist[n][D + 1][C + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= D; j++)
        {
            for (int k = 0; k <= C; k++)
            {
                dist[i][j][k] = INT_MAX;
            }
        }
    }

    q.push(nodes(0, min(A[0], D), min(A[0] == 0 ? 1 : 0, C), 0));
    while (!q.empty())
    {
        nodes top = q.top();
        q.pop();
        if (dist[top.node][top.spcl][top.n_spcl] != INT_MAX) //har state ek hi bar update hoga and wahi minimum value hoga uska
            continue;
        dist[top.node][top.spcl][top.n_spcl] = min(top.weight, dist[top.node][top.spcl][top.n_spcl]);
        vector<newnode> adj = list[top.node];
        for (int j = 0; j < adj.size(); j++)
        {
            newnode ad = adj[j];
            if (top.weight + ad.weight < dist[ad.n][min(ad.speciality + top.spcl, D)][min(!ad.speciality + top.n_spcl, C)])
                q.push(nodes(ad.n, min(ad.speciality + top.spcl, D), min(!ad.speciality + top.n_spcl, C), top.weight + ad.weight));
        }
    }
    return dist[n - 1][D][C] == INT_MAX ? -1 : dist[n - 1][D][C];
}

#include <bits/stdc++.h>
using namespace std;

/* lis() returns the length of the longest 
increasing subsequence in arr[] of size n */
int lis(int arr[], int n)
{
    int lis[n];
    memset(lis,1,sizeof(lis));//base case

    /* Compute optimized LIS values in 
	bottom up manner */

    for (int end = 1; end < n; end++)
    {
        for (int start = 0; start < end; start++)

            if ( arr[start] < arr[end] && lis[end] < lis[start] + 1)
                lis[end] = lis[start] + 1;
    }
    
    // Return maximum value in lis[]
    return *max_element(lis, lis + n);
}

/* Driver program to test above function */
int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of lis is %d\n", lis(arr, n));

    return 0;
}
