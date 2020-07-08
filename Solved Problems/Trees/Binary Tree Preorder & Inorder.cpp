/**
 * Question - Binary Tree From Inorder And Preorder
Problem Description

Given preorder and inorder traversal of a tree, construct the binary tree.

NOTE: You may assume that duplicates do not exist in the tree.



Problem Constraints
1 <= number of nodes <= 105



Input Format
First argument is an integer array A denoting the preorder traversal of the tree.

Second argument is an integer array B denoting the inorder traversal of the tree.



Output Format
Return the root node of the binary tree.



Example Input
Input 1:

 A = [1, 2, 3]
 B = [2, 1, 3]
Input 2:

 A = [1, 6, 2, 3]
 B = [6, 1, 3, 2]


Example Output
Output 1:

   1
  / \
 2   3
Output 2:

   1  
  / \
 6   2
    /
   3


Example Explanation
Explanation 1:

 Create the binary tree and return the root node of the tree.
Approach is similar to postorder and inorder traversal
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
TreeNode *constructTree(map<int, int> &m, vector<int> &A, int start, int end, int &preindex)
{
    if (start > end)
        return NULL;
    TreeNode *root = new TreeNode(A[preindex]);
    int mid = m[A[preindex]];
    preindex++;
    root->left = constructTree(m, A, start, mid - 1, preindex);
    root->right = constructTree(m, A, mid + 1, end, preindex);
    return root;
}
TreeNode *Solution::buildTree(vector<int> &A, vector<int> &B)
{
    map<int, int> m;
    int n = A.size();
    for (int i = 0; i < n; i++)
        m[B[i]] = i;
    int preindex = 0;
    return constructTree(m, A, 0, n - 1, preindex);
}
