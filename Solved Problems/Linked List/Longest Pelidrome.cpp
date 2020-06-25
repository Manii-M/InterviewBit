/**
 * Question - 
 * Longest Palindromic List
Problem Description

Given a linked list of integers. Find and return the length of the longest palindrome list that exists in that linked list.

A palindrome list is a list that reads the same backward and forward.

Expected memory complexity : O(1)



Problem Constraints
1 <= length of the linked list <= 2000

1 <= Node value <= 100



Input Format
The only argument given is head pointer of the linked list.



Output Format
Return the length of the longest palindrome list.



Example Input
Input 1:

 2 -> 3 -> 3 -> 3
Input 2:

 2 -> 1 -> 2 -> 1 ->  2 -> 2 -> 1 -> 3 -> 2 -> 2


Example Output
Output 1:

 3
Output 2:

 5


Example Explanation
Explanation 1:

 3 -> 3 -> 3 is largest palindromic sublist
Explanation 2:

 2 -> 1 -> 2 -> 1 -> 2 is largest palindromic sublist.
 /*
 * Approach - Pelindrome will have an middle element we need to check before middle and after middle all the values are same or not
 * we can keep reversing the linked lisst and check and count the max length
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int compare(ListNode *forward, ListNode *backward)
{
    int count = 0, max_length = 0;
    ListNode *A = forward, *B = backward;
    while (forward && backward && forward->val == backward->val)
    {
        count += 2;
        forward = forward->next;
        backward = backward->next;
    }
    max_length = max(count, max_length);
    if (A)
        forward = A->next;
    backward = B;
    count = 1;
    while (forward && backward && forward->val == backward->val)
    {
        count += 2;
        forward = forward->next;
        backward = backward->next;
    }
    max_length = max(count, max_length);
    if (B)
        backward = B->next;
    forward = A;
    count = 1;
    while (forward && backward && forward->val == backward->val)
    {
        count += 2;
        forward = forward->next;
        backward = backward->next;
    }
    return max(max_length, count);
}

int Solution::solve(ListNode *A)
{
    ListNode *curr = A, *next = NULL, *prev = NULL;
    int max_length = 1;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        max_length = max(max_length, compare(next, curr));
        prev = curr;
        curr = next;
    }
    return max_length;
}
