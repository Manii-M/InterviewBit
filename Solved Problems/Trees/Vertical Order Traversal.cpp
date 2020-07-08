/**
 * Question 
 * Vertical Order traversal
Problem Description

Given a binary tree, return a 2-D array with vertical order traversal of it. Go through the example and image for more details.


NOTE: If 2 Tree Nodes shares the same vertical level then the one with lesser depth will come first.



Problem Constraints
1 <= number of nodes <= 105



Input Format
First and only arument is a pointer to the root node of binary tree, A.



Output Format
Return a 2D array denoting the vertical order traversal of tree as shown.



Example Input
Input 1:

      6
    /   \
   3     7
  / \     \
 2   5     9
Input 2:

      1
    /   \
   3     7
  /       \
 2         9


Example Output
Output 1:

 [
    [2],
    [3],
    [6, 5],
    [7],
    [9]
 ]
Output 2:

 [
    [2],
    [3],
    [1],
    [7],
    [9]
 ]


Example Explanation
Explanation 1:

 First row represent the verical line 1 and so on.

*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * a
 * };
 */
//  void vOrderTraverse(map<int,vector<int>> &m,TreeNode *A,int dist) // ths function for preorder vertiacl traversal 
//  {
//     if(A==NULL)
//         return;
//     m[dist].push_back(A->val);
//     vOrderTraverse(m,A->left,dist-1);
//     vOrderTraverse(m,A->right,dist+1);

//  }
/**
 * Approach - in this question we can maintaint the horizontal distances for each vertical line, and any traversal of the treee will give the answer.
*/
vector<vector<int>> Solution::verticalOrderTraversal(TreeNode *A)
{
    if (A == NULL)
        return {};
    map<int, vector<int>> m;
    vector<vector<int>> answer;
    queue<pair<TreeNode *, int>> q;
    int dist = 0;
    q.push(make_pair(A, dist));//level order vertical order traversal
    while (!q.empty())
    {
        pair<TreeNode *, int> node = q.front();
        dist = node.second;
        m[dist].push_back(node.first->val);
        q.pop();
        if (node.first->left)
            q.push(make_pair(node.first->left, dist - 1));
        if (node.first->right)
            q.push(make_pair(node.first->right, dist + 1));
    }
    for (auto it = m.begin(); it != m.end(); it++)
        answer.push_back(it->second);
    return answer;
}
