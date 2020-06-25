/**
 * K reverse linked list
Problem Description

Given a singly linked list A and an integer B, reverse the nodes of the list B at a time and return modified linked list.



Problem Constraints
1 <= |A| <= 103

B always divides A



Input Format
The first argument of input contains a pointer to the head of the linked list.

The second arugment of input contains the integer, B.



Output Format
Return a pointer to the head of the modified linked list.



Example Input
Input 1:

 A = [1, 2, 3, 4, 5, 6]
 B = 2
Input 2:

 A = [1, 2, 3, 4, 5, 6]
 B = 3


Example Output
Output 1:

 [2, 1, 4, 3, 6, 5]
Output 2:

 [3, 2, 1, 6, 5, 4]


Example Explanation
Explanation 1:

 For the first example, the list can be reversed in groups of 2.
    [[1, 2], [3, 4], [5, 6]]
 After reversing the K-linked list
    [[2, 1], [4, 3], [6, 5]]
Explanation 2:

 For the second example, the list can be reversed in groups of 3.
    [[1, 2, 3], [4, 5, 6]]
 After reversing the K-linked list
    [[3, 2, 1], [6, 5, 4]]
 *
 /* Approach - there are two approaches.
 * Ap 1 - use stack and put all the B elements in to the stack and again join them bacck to linkedlist
 * TC- O(n) SC - O(n)
 * Ap 2 - we can detach the B length linked list and create new reverse linked list using the same nodes
 * TC - O(n) SC-O(1)
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *reverse(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}

ListNode *Solution::reverseList(ListNode *A, int B)
{

    ListNode *new_head = NULL, *curr = NULL, *new_list = NULL, *prev = NULL, *next = NULL;
    while (A != NULL)
    {
        int nodes = B;
        while (A != NULL && nodes > 0)
        {
            if (nodes == B)
                new_list = A;
            prev = A;
            A = A->next;
            nodes--;
        }
        prev->next = NULL;

        if (new_head == NULL)
        {
            curr = new_list;
            new_head = reverse(new_list);
        }
        else
        {
            next = new_list;
            curr->next = reverse(new_list);
            curr = next;
        }
    }
    return new_head;
}
