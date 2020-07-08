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
        return true;
    return false;
}
int Solution::isValidBST(TreeNode *A)
{
    return IsBSTUtil(A, INT_MIN, INT_MAX);
}
