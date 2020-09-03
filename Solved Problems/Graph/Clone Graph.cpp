/**
 * Clone Graph
Problem Description

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.



Problem Constraints
1 <= Number of nodes <= 105



Input Format
First and only argument is a node A denoting the root of the undirected graph.



Output Format
Return the node denoting the root of the new clone graph.



Example Input
Input 1:

      1
    / | \
   3  2  4
        / \
       5   6
Input 2:

      1
     / \
    3   4
   /   /|\
  2   5 7 6


Example Output
Output 1:

 Output will the same graph but with new pointers:
      1
    / | \
   3  2  4
        / \
       5   6
Output 2:

      1
     / \
    3   4
   /   /|\
  2   5 7 6


Example Explanation
Explanation 1:

 We need to return the same graph, but the pointers to the node should be different.
*/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node)
{
    map<UndirectedGraphNode *, UndirectedGraphNode *> m;
    queue<UndirectedGraphNode *> q;
    UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
    m[node] = root;
    q.push(node);
    while (!q.empty())
    {
        UndirectedGraphNode *top = q.front();
        q.pop();
        vector<UndirectedGraphNode *> v = top->neighbors;
        for (int i = 0; i < v.size(); i++)
        {
            if (m[v[i]] == NULL)
            {
                m[v[i]] = new UndirectedGraphNode(v[i]->label);
                q.push(v[i]);
            }
            m[top]->neighbors.push_back(m[v[i]]);
        }
    }
    return root;
}
