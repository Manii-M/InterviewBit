/**
 * Question
 * Partition List
Problem Description

Given a linked list A and a value B, partition it such that all nodes less than B come before nodes greater than or equal to B.

You should preserve the original relative order of the nodes in each of the two partitions.



Problem Constraints
1 <= |A| <= 106

1 <= A[i], B <= 109



Input Format
The first argument of input contains a pointer to the head to the given linked list.

The second argument of input contains an integer, B.



Output Format
Return a pointer to the head of the modified linked list.



Example Input
Input 1:

A = [1, 4, 3, 2, 5, 2]
B = 3
Input 2:

A = [1, 2, 3, 1, 3]
B = 2


Example Output
Output 1:

[1, 2, 2, 4, 3, 5]
Output 2:

[1, 1, 2, 3, 3]


Example Explanation
Explanation 1:

 [1, 2, 2] are less than B wheread [4, 3, 5] are greater than or equal to B.
Explanation 2:

 [1, 1] are less than B wheread [2, 3, 3] are greater than or equal to B.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::partition(ListNode *A, int B)
{
    ListNode *lesser = NULL, *greater = NULL;
    ListNode *less_head = NULL, *great_head = NULL, *head = A;
    while (A)
    {
        if (A->val < B)
        {
            if (less_head == NULL)
            {
                lesser = A;
                less_head = lesser;
            }
            else
            {
                lesser->next = A;
                lesser = lesser->next;
            }
        }
        else if (A->val >= B)
        {
            if (great_head == NULL)
            {
                greater = A;
                great_head = greater;
            }
            else
            {
                greater->next = A;
                greater = greater->next;
            }
        }

        A = A->next;
    }
    if (less_head == NULL)
        return head;
    if (great_head == NULL)
        return head;
    if (less_head && great_head)
    {
        lesser->next = great_head;
        greater->next = NULL;
        return less_head;
    }
    return NULL;
}
