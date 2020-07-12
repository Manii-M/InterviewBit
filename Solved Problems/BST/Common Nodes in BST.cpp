/**
 * Common Nodes in Two BST
Problem Description

Given two BST's A and B, return the (sum of all common nodes in both A and B) % (109 +7) .

In case there is no common node, return 0.

NOTE:

Try to do it one pass through the trees.



Problem Constraints
1 <= Number of nodes in the tree A and B <= 105

1 <= Node values <= 106



Input Format
First argument represents the root of BST A.

Second argument represents the root of BST B.



Output Format
Return an integer denoting the (sum of all common nodes in both BST's A and B) % (109 +7) .



Example Input
Input 1:

 Tree A:
    5
   / \
  2   8
   \   \
    3   15
        /
        9

 Tree B:
    7
   / \
  1  10
   \   \
    2  15
       /
      11
Input 2:

  Tree A:
    7
   / \
  1   10
   \   \
    2   15
        /
       11

 Tree B:
    7
   / \
  1  10
   \   \
    2  15
       /
      11


Example Output
Output 1:

 17
Output 2:

 46


Example Explanation
Explanation 1:

 Common Nodes are : 2, 15
 So answer is 2 + 15 = 17
Explanation 2:

 Common Nodes are : 7, 2, 1, 10, 15, 11
 So answer is 7 + 2 + 1 + 10 + 15 + 11 = 46
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
void traverse(TreeNode *A, map<int, int> &m)
{
    if (A == NULL)
        return;
    traverse(A->left, m);
    m[A->val]++;
    traverse(A->right, m);
}
int Solution::solve(TreeNode *A, TreeNode *B)
{
    map<int, int> m;
    traverse(A, m);
    traverse(B, m);
    long long int sum = 0, mod = 1000000007;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second > 1)
            sum += it->first;
        if (sum >= mod)
            sum -= mod;
    }
    return sum % mod;
}
