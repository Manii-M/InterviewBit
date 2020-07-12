/**
 * Largest BST Subtree
Problem Description

Given a Binary Tree A with N nodes.

Write a function that returns the size of the largest subtree which is also a Binary Search Tree (BST).

If the complete Binary Tree is BST, then return the size of whole tree.

NOTE:

Largest subtree means subtree with most number of nodes.


Problem Constraints
1 <= N <= 105



Input Format
First and only argument is an pointer to root of the binary tree A.



Output Format
Return an single integer denoting the size of the largest subtree which is also a BST.



Example Input
Input 1:

     10
    / \
   5  15
  / \   \ 
 1   8   7
Input 2:

     5
    / \
   3   8
  / \ / \
 1  4 7  9


Example Output
Output 1:

 3
Output 2:

 7


Example Explanation
Explanation 1:

 Largest BST subtree is
                            5
                           / \
                          1   8
Explanation 2:

 Given binary tree itself is BST.
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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
bool IsBSTUtil(TreeNode *A, int min, int max)
{
    if (A == NULL)
        return true;
    if (A->val < max && A->val > min && IsBSTUtil(A->left, min, A->val) && IsBSTUtil(A->right, A->val, max))
    {
        return true;
    }
    return false;
}
int countNodes(TreeNode *A, int &count)
{
    if (A == NULL)
        return 0;
    int left = countNodes(A->left, count);
    int right = countNodes(A->right, count);
    int c = left + right + 1;
    if (count < c && IsBSTUtil(A, INT_MIN, INT_MAX))
        count = c;
    return c;
}

int Solution::solve(TreeNode *A)
{
    int answer = 0;
    int nodes = countNodes(A, answer);
    return answer;
}
