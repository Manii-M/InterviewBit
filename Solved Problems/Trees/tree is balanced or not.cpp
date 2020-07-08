/**
 * Question - 
 * Balanced Binary Tree
Problem Description

Given a root of binary tree A, determine if it is height-balanced.

A height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.



Problem Constraints
1 <= size of tree <= 100000



Input Format
First and only argument is the root of the tree A.



Output Format
Return 0 / 1 ( 0 for false, 1 for true ) for this problem.



Example Input
Input 1:

    1
   / \
  2   3
Input 2:

 
       1
      /
     2
    /
   3


Example Output
Output 1:

1
Output 2:

0


Example Explanation
Explanation 1:

It is a complete binary tree.
Explanation 2:

Because for the root node, left subtree has depth 2 and right subtree has depth 0. 
Difference = 2 > 1. 
Approach - there two ways to do this first calculate the height of each subtree and check if they are balanced or not 
2nd is we can keep calculating the height and that time only we can check that the 
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
struct TreeInfo
{
    int height;
    bool isBal;
    TreeInfo(int ht, bool bal) : height(ht), isBal(bal) {}
};

TreeInfo *checkIsBalanced(TreeNode *A)
{
    if (A == NULL)
        return new TreeInfo(-1, true);
    TreeInfo *left_info = checkIsBalanced(A->left);
    TreeInfo *right_info = checkIsBalanced(A->right);
    if (left_info->isBal && right_info->isBal && abs(left_info->height - right_info->height) < 2)
        return new TreeInfo(max(left_info->height, right_info->height) + 1, true);
    return new TreeInfo(max(left_info->height, right_info->height) + 1, false);
}

int Solution::isBalanced(TreeNode *A)
{
    TreeInfo *answer = checkIsBalanced(A);
    return answer->isBal;
}
