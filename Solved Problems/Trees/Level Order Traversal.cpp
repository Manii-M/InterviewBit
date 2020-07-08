/**
 * Question - 
 * Level Order
Problem Description

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).



Problem Constraints
1 <= number of nodes <= 105



Input Format
First and only argument is root node of the binary tree, A.



Output Format
Return a 2D integer array denoting the zigzag level order traversal of the given binary tree.



Example Input
Input 1:

    3
   / \
  9  20
    /  \
   15   7
Input 2:

   1
  / \
 6   2
    /
   3


Example Output
Output 1:

 [
   [3],
   [9, 20],
   [15, 7]
 ]
Output 2:

 [ 
   [1]
   [6, 2]
   [3]
 ]


Example Explanation
Explanation 1:

 Return the 2D array. Each row denotes the traversal of each level.
Approach - use queue to get the each level nodes one by one and append them back in the queue to process later which will give us the level order traversal
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
vector<vector<int>> Solution::levelOrder(TreeNode *A)
{
    vector<vector<int>> answer;
    queue<TreeNode *> node_q;
    node_q.push(A);
    node_q.push(NULL);
    while (!node_q.empty())
    {
        vector<int> ele;
        if (node_q.front() == NULL)
            break;
        while (!node_q.empty() && node_q.front())
        {
            TreeNode *temp = node_q.front();
            ele.push_back(temp->val);
            if (temp->left)
                node_q.push(temp->left);
            if (temp->right)
                node_q.push(temp->right);
            node_q.pop();
        }
        node_q.push(NULL);
        node_q.pop();
        answer.push_back(ele);
    }
    return answer;
}
