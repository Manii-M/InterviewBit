/**
 * 2-Sum Binary Tree
Problem Description

Given a binary search tree A, where each node contains a positive integer, and an integer B, you have to find whether or not there exist two different nodes X and Y such that X.value + Y.value = B.

Return 1 to denote that two such nodes exist. Return 0, otherwise.



Problem Constraints
1 <= size of tree <= 100000

1 <= B <= 109



Input Format
First argument is the head of the tree A.

Second argument is the integer B.



Output Format
Return 1 if such a pair can be found, 0 otherwise.



Example Input
Input 1:

         10
         / \
        9   20

B = 19
Input 2:

 
          10
         / \
        9   20

B = 40


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 10 + 9 = 19. Hence 1 is returned.
Explanation 2:

 No such pair exists.
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
void findPair(map<int, int> &m, TreeNode *A, int B)
{
    if (A == NULL)
        return;
    findPair(m, A->left, B);
    if (m[B - (A->val)] > 0 || m[INT_MIN] > 0)
    {
        m[INT_MIN] = 1;
        return;
    }
    m[A->val] = 1;
    findPair(m, A->right, B);
}
int Solution::t2Sum(TreeNode *A, int B)
{
    map<int, int> m;
    findPair(m, A, B);
    if (m[INT_MIN] > 0)
        return 1;
    return 0;
}
