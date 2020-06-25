/**
 * Question - Add Two Numbers as Lists
Problem Description

You are given two linked lists, A and B representing two non-negative numbers.

The digits are stored in reverse order and each of their nodes contain a single digit.

Add the two numbers and return it as a linked list.



Problem Constraints
1 <= |A|, |B| <= 105



Input Format
The first argument of input contains a pointer to the head of linked list A.

The second argument of input contains a pointer to the head of linked list B.



Output Format
Return a pointer to the head of the required linked list.



Example Input
Input 1:

 
 A = [2, 4, 3]
 B = [5, 6, 4]
Input 2:

 
 A = [9, 9]
 B = [1]


Example Output
Output 1:

 
 [7, 0, 8]
Output 2:

 
 [0, 0, 1]


Example Explanation
Explanation 1:

 A = 342 and B = 465. A + B = 807. 
Explanation 2:

 A = 99 and B = 1. A + B = 100.
 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void attachRemainingNodes(ListNode *remaining, int &carry)
{
    ListNode *rest = remaining;
    while (rest && (rest->val + carry > 9))
    {
        rest->val = (rest->val + carry) % 10;
        rest = rest->next;
    }
    if (rest != NULL)
    {
        rest->val = rest->val + carry;
        carry = 0;
    }
}
ListNode *Solution::addTwoNumbers(ListNode *A, ListNode *B)
{
    int carry = 0;
    ListNode *head = A, *prev = NULL;
    while (A && B)
    {
        if ((A->val + B->val + carry) > 9)
        {
            A->val = (A->val + B->val + carry) % 10;
            carry = 1;
        }
        else
        {
            A->val = A->val + B->val + carry;
            carry = 0;
        }
        prev = A;
        A = A->next;
        B = B->next;
    }

    if (A == NULL)
    {
        prev->next = B; //adding B to end of the A beacuase A is the answer list
        attachRemainingNodes(B, carry);
    }
    else if (B == NULL)
    {
        attachRemainingNodes(A, carry);
    }
    if (carry == 1)
    {
        A = head;
        while (A && A->next)
        {
            A = A->next;
        }
        A->next = new ListNode(1);
    }

    return head;
}
