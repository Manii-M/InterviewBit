/**
 * Distance between Nodes of BST
Problem Description

Given a binary search tree.
Return the distance between two nodes with given two keys B and C. It may be assumed that both keys exist in BST.

NOTE: Distance between two nodes is number of edges between them.



Problem Constraints
1 <= Number of nodes in binary tree <= 1000000

0 <= node values <= 109



Input Format
First argument is a root node of the binary tree, A.

Second argument is an integer B.

Third argument is an integer C.



Output Format
Return an integer denoting the distance between two nodes with given two keys B and C



Example Input
Input 1:

    
         5
       /   \
      2     8
     / \   / \
    1   4 6   11
 B = 2
 C = 11
Input 2:

    
         6
       /   \
      2     9
     / \   / \
    1   4 7   10
 B = 2
 C = 6


Example Output
Output 1:

 3
Output 2:

 1


Example Explanation
Explanation 1:

 Path between 2 and 11 is: 2 -> 5 -> 8 -> 11. Distance will be 3.
Explanation 2:

 Path between 2 and 6 is: 2 -> 6. Distance will be 1
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
TreeNode *findLCA(TreeNode *A, int B, int C)
{
    if (A == NULL)
        return NULL;
    if (A->val == B || A->val == C)
        return A;
    TreeNode *left = findLCA(A->left, B, C);
    TreeNode *right = findLCA(A->right, B, C);
    if (left && right)
        return A;
    return left ? left : right;
}

TreeNode *dist(TreeNode *lca, int n, int &count)
{
    if (lca == NULL)
        return NULL;

    if (n == lca->val)
        return lca;
    count++;
    TreeNode *left = dist(lca->left, n, count);
    TreeNode *right = dist(lca->right, n, count);

    if (left == NULL && right == NULL)
    {
        count--;
        return NULL;
    }
    return lca;
}
int Solution::solve(TreeNode *A, int B, int C)
{
    TreeNode *LCA = findLCA(A, B, C);

    int count = 0;

    TreeNode *kj = dist(LCA, B, count);

    int bi = count;

    count = 0;

    TreeNode *ki = dist(LCA, C, count);

    return bi + count;
}
