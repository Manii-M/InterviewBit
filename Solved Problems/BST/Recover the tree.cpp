/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * Recover Binary Search Tree
Problem Description

Two elements of a binary search tree (BST),represented by root A are swapped by mistake. Tell us the 2 values swapping which the tree will be restored.

A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?



Problem Constraints
1 <= size of tree <= 100000



Input Format
First and only argument is the head of the tree,A



Output Format
Return the 2 elements which need to be swapped.



Example Input
Input 1:

 
         1
        / \
       2   3
Input 2:

 
         2
        / \
       3   1



Example Output
Output 1:

 [2, 1]
Output 2:

 [3, 1]


Example Explanation
Explanation 1:

Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST 
Explanation 2:

Swapping 1 and 3 will change the BST to be 
         2
        / \
       1   3
which is a valid BST 
 */
void recoverBSTUtil(TreeNode *A, int &first, int &middle, int &last, int &prev)
{
    if (A == NULL)
        return;

    recoverBSTUtil(A->left, first, middle, last, prev);
    if (prev != INT_MIN && A->val < prev && first == INT_MIN)
    {
        first = prev;
        middle = A->val;
    }
    else if (prev != INT_MIN && A->val < prev && last == INT_MIN)
        last = A->val;
    prev = A->val;
    recoverBSTUtil(A->right, first, middle, last, prev);
}
void recoverBST(TreeNode *A, int &e1, int &e2)
{
    int first, middle, last, prev;
    first = middle = last = prev = INT_MIN;
    recoverBSTUtil(A, first, middle, last, prev);
    if (first != INT_MIN && last != INT_MIN)
    {
        e1 = last;
        e2 = first;
    }
    else
    {
        e1 = middle;
        e2 = first;
    }
}
vector<int> Solution::recoverTree(TreeNode *A)
{
    int e1, e2;
    vector<int> answer;
    recoverBST(A, e1, e2);
    answer.push_back(e1);
    answer.push_back(e2);
    return answer;
}
