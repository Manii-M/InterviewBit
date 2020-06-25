/**
 * Question - 
 * Merge Two Sorted Lists
Problem Description

Merge two sorted linked lists A and B and return it as a new list.

The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.



Problem Constraints
0 <= |A|, |B| <= 105



Input Format
The first argument of input contains a pointer to the head of linked list A.

The second argument of input contains a pointer to the head of linked list B.



Output Format
Return a pointer to the head of the merged linked list.



Example Input
Input 1:

 A = 5 -> 8 -> 20
 B = 4 -> 11 -> 15
Input 2:

 A = 1 -> 2 -> 3
 B = Null


Example Output
Output 1:

 4 -> 5 -> 8 -> 11 -> 15 -> 20
Output 2:

 1 -> 2 -> 3


Example Explanation
Explanation 1:

 Merging A and B will result in 4 -> 5 -> 8 -> 11 -> 15 -> 20 
Explanation 2:

 We don't need to merge as B is empty. 
 *
 * Approach - do same we do for the to merge two sorted arrays
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::mergeTwoLists(ListNode *A, ListNode *B)
{

    ListNode *head = NULL, *curr = NULL;
    while (A && B)
    {
        if (A->val < B->val)
        {
            if (head == NULL)
            {
                head = A;
                curr = head;
            }
            else
            {
                curr->next = A;
                curr = curr->next;
            }
            A = A->next;
        }
        else if (A->val > B->val)
        {
            if (head == NULL)
            {
                head = B;
                curr = head;
            }
            else
            {

                curr->next = B;
                curr = curr->next;
            }
            B = B->next;
        }
        else
        {
            if (head == NULL)
            {
                head = A;
                curr = A;
                A = A->next;
                curr->next = B;
                curr = curr->next;
                B = B->next;
            }
            else
            {
                curr->next = A;
                A = A->next;
                curr = curr->next;
                curr->next = B;
                B = B->next;
                curr = curr->next;
            }
        }
    }
    if (A != NULL)
    {
        curr->next = A;
        // curr=curr->next;
    }
    if (B != NULL)
    {
        curr->next = B;
        // curr=curr->next;
    }
    return head;
}
