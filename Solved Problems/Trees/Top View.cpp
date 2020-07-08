/**
 * Question - 
 * TOP VIEW
Problem Description

Given a binary tree of integers denoted by root A. Return an array of integers representing the top view of the Binary tree.

Right view of a Binary Tree is a set of nodes visible when the tree is visited from top.

Return the nodes in any order.



Problem Constraints
1 <= Number of nodes in binary tree <= 100000

0 <= node values <= 10^9



Input Format
First and only argument is head of the binary tree A.



Output Format
Return an array, representing the top view of the binary tree.



Example Input
Input 1:

 
            1
          /   \
         2    3
        / \  / \
       4   5 6  7
      /
     8 
Input 2:

 
            1
           /  \
          2    3
           \
            4
             \
              5


Example Output
Output 1:

 [1, 2, 4, 8, 3, 7]
Output 2:

 [1, 2, 3]


Example Explanation
Explanation 1:

Top view is described.
Explanation 2:

Top view is described.
Approach - use the same approach usedin vertical order traversal just take the first value of each vertical line(array)
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// void findTopView(map<int,vector<int>> &m,TreeNode *A,int dist)
// {
//     if(A==NULL)
//         return;
//     m[dist].push_back(A->val);
//     findTopView(m,A->left,dist-1);
//     findTopView(m,A->right,dist+1);
// }
vector<int> Solution::solve(TreeNode *A)
{
    if (A == NULL)
        return {};
    vector<int> answer;
    map<int, vector<int>> m;
    queue<pair<TreeNode *, int>> q;
    int dist = 0;
    q.push(make_pair(A, dist));

    while (!q.empty())
    {
        pair<TreeNode *, int> node = q.front();
        q.pop();
        dist = node.second;
        m[dist].push_back(node.first->val);
        if (node.first->left)
            q.push(make_pair(node.first->left, dist - 1));
        if (node.first->right)
            q.push(make_pair(node.first->right, dist + 1));
    }
    for (auto it = m.begin(); it != m.end(); it++)
        answer.push_back(it->second[0]);
    return answer;
}
