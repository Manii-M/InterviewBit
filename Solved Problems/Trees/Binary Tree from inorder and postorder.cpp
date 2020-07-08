/**
 * Question - 
 * Binary Tree From Inorder And Postorder
Problem Description

Given inorder and postorder traversal of a tree, construct the binary tree.

NOTE: You may assume that duplicates do not exist in the tree.



Problem Constraints
1 <= number of nodes <= 105



Input Format
First argument is an integer array A denoting the inorder traversal of the tree.

Second argument is an integer array B denoting the postorder traversal of the tree.



Output Format
Return the root node of the binary tree.



Example Input
Input 1:

 A = [2, 1, 3]
 B = [2, 3, 1]
Input 2:

 A = [6, 1, 3, 2]
 B = [6, 3, 2, 1]


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
Approach - Postorder  LRN and Inorder - LNR , the last element of the postorder will be t
he root of the tree/subtree and that element left and right in inorder will form the LST and RST.
using this observation we can construct the tree.
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
TreeNode *constructTree(map<int, int> &map_i, vector<int> &post_order, int start, int end, int &pindex)
{
    if (start > end)
        return NULL;
    TreeNode *root = new TreeNode(post_order[pindex]);
    int mid = map_i[post_order[pindex]];
    pindex--;
    if (start == end)
        return root;
    root->right = constructTree(map_i, post_order, mid + 1, end, pindex);
    root->left = constructTree(map_i, post_order, start, mid - 1, pindex);
    return root;
}
TreeNode *Solution::buildTree(vector<int> &A, vector<int> &B)
{
    map<int, int> map_i;
    for (int i = 0; i < A.size(); i++)
        map_i[A[i]] = i;
    int n = A.size() - 1;
    return constructTree(map_i, B, 0, n, n);
}
