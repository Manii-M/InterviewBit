/**
 * Reverse Link List II
Problem Description

Reverse a linked list A from position B to C.

NOTE: Do it in-place and in one-pass.



Problem Constraints
1 <= |A| <= 106

1 <= B <= C <= |A|



Input Format
The first argument contains a pointer to the head of the given linked list, A.

The second arugment contains an integer, B.

The third argument contains an integer C.



Output Format
Return a pointer to the head of the modified linked list.



Example Input
Input 1:

 A = 1 -> 2 -> 3 -> 4 -> 5
 B = 2
 C = 4

Input 2:

 A = 1 -> 2 -> 3 -> 4 -> 5
 B = 1
 C = 5


Example Output
Output 1:

 1 -> 4 -> 3 -> 2 -> 5
Output 2:

 5 -> 4 -> 3 -> 2 -> 1


Example Explanation
Explanation 1:

 In the first example, we want to reverse the highlighted part of the given linked list : 1 -> 2 -> 3 -> 4 -> 5 
 Thus, the output is 1 -> 4 -> 3 -> 2 -> 5 
Explanation 2:

 In the second example, we want to reverse the highlighted part of the given linked list : 1 -> 4 -> 3 -> 2 -> 5  
 Thus, the output is 5 -> 4 -> 3 -> 2 -> 1 
 *
 /* Approach - here we will be having diffrent cases and each case we can handle by detaching the list and re-attaching it back to the originall list.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *reverse(ListNode *A)
{
    if (A == NULL || A->next == NULL)
        return A;
    ListNode *rest = reverse(A->next);
    A->next->next = A;
    A->next = NULL;
    return rest;
}
ListNode *Solution::reverseBetween(ListNode *A, int B, int C)
{
    ListNode *start = NULL, *end = NULL, *head = A, *prev = NULL, *prevEnd = NULL;
    int nodes = C - B;

    while (head != NULL && B > 1)
    {
        prev = head;
        head = head->next;
        B--;
    }

    start = head;
    end = head;

    while (end != NULL && nodes > 0)
    {
        prevEnd = end;
        end = end->next;
        nodes--;
    }

    if (start == A && end->next == NULL) //when whole linked list has to be reversed
        return reverse(A);
    else if (start == A && end != NULL && end->next != NULL) //when reverse LL starts from the head and end in between in the list
    {
        ListNode *remaining = end->next;
        end->next = NULL;
        ListNode *new_head = reverse(start);
        start->next = remaining;
        return new_head;
    }
    else if (prev != NULL && end == NULL) //when not start from the starting but ends at the end
    {

        ListNode *new_head = reverse(start);
        prev->next = new_head;
        return A;
    }
    else //when LL is in between
    {

        ListNode *endNext = end->next;
        end->next = NULL;
        ListNode *new_head = reverse(start);
        prev->next = new_head;
        start->next = endNext;
        return A;
    }
    return A;
}
