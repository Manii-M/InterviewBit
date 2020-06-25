/**
 * Reorder List
Problem Description

Given a singly linked list A

 A: A0 → A1 → … → An-1 → An 
reorder it to:

 A0 → An → A1 → An-1 → A2 → An-2 → … 
You must do this in-place without altering the nodes' values.



Problem Constraints
1 <= |A| <= 106



Input Format
The first and the only argument of input contains a pointer to the head of the linked list A.



Output Format
Return a pointer to the head of the modified linked list.



Example Input
Input 1:

 A = [1, 2, 3, 4, 5] 
Input 2:

 A = [1, 2, 3, 4] 


Example Output
Output 1:

 [1, 5, 2, 4, 3] 
Output 2:

 [1, 4, 2, 3] 


Example Explanation
Explanation 1:

 The array will be arranged to [A0, An, A1, An-1, A2].
Explanation 2:

 The array will be arranged to [A0, An, A1, An-1, A2].
 *
 /* Approach - reach at the middle of the list, make two lists from there by detaching them and reversed the second list
 * and merger both of them by alternate nodes.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *reverse(ListNode *B)
{
    if (B == NULL || B->next == NULL)
        return B;

    ListNode *rest = reverse(B->next);
    B->next->next = B;
    B->next = NULL;
    return rest;
}
ListNode *Solution::reorderList(ListNode *A)
{

    ListNode *slowPtr = A, *fastPtr = A, *prev = NULL;
    while (slowPtr != NULL && fastPtr != NULL && fastPtr->next != NULL)
    {
        prev = slowPtr;
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    ListNode *B = NULL;
    if (fastPtr == NULL)
    {
        B = prev->next;
        prev->next = NULL;
    }
    else if (fastPtr != NULL && fastPtr->next == NULL)
    {
        B = slowPtr->next;
        slowPtr->next = NULL;
    }

    B = reverse(B);
    ListNode *curr = A, *next = NULL;
    prev = NULL;
    while (B != NULL && curr != NULL)
    {
        next = curr->next;
        curr->next = B;
        prev = B->next;
        B->next = next;
        B = prev;
        curr = next;
    }
    return A;
}
