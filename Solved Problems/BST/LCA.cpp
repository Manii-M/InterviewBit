/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * Least Common Ancestor
Problem Description

Find the lowest common ancestor in an unordered binary tree A given two values B and C in the tree.

Lowest common ancestor : the lowest common ancestor (LCA) of two nodes and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants.



Problem Constraints
1 <= size of tree <= 100000

1 <= B, C <= 109



Input Format
First argument is head of tree A.

Second argument is integer B.

Third argument is integer C.



Output Format
Return the LCA.



Example Input
Input 1:

 
      1
     /  \
    2    3
B = 2
C = 3
Input 2:

      1
     /  \
    2    3
   / \
  4   5
B = 4
C = 5


Example Output
Output 1:

 1
Output 2:

 2


Example Explanation
Explanation 1:

 LCA is 1.
Explanation 2:

 LCA is 2.
 */
TreeNode *findPath(TreeNode *A, int B, vector<int> &path1)
{
    if (A == NULL)
        return NULL;
    path1.push_back(A->val);

    if (A->val == B)
        return A;

    TreeNode *left = findPath(A->left, B, path1);
    TreeNode *right = findPath(A->right, B, path1);

    if (left == NULL && right == NULL)
    {
        path1.pop_back();
        return NULL;
    }
    return A;
}
int Solution::lca(TreeNode *A, int B, int C)
{
    vector<int> path1, path2;

    TreeNode *left = findPath(A, B, path1);
    TreeNode *right = findPath(A, C, path2);
    int i = 0;
    for (i = 0; i < path1.size() && i < path2.size(); i++)
        if (path1[i] != path2[i])
            break;
    if (i > 0)
        return path1[i - 1];
    if (A->val == B && A->val == C)
        return A->val;
    return -1;
}
