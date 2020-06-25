/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *Solution::removeNthFromEnd(ListNode *A, int B)
{
    ListNode *start = A, *end = A;
    while (B > 0 && end != NULL)
    {
        end = end->next;
        B--;
    }

    if (end == NULL) //handling the case when end reaches the end which means we need to change the head
    {
        A = start->next;
        start->next = NULL;
        return A;
    }

    while (start != NULL && end != NULL && end->next != NULL)
    {
        start = start->next;
        end = end->next;
    }

    if (start != NULL && start->next != NULL)
    {
        start->next = start->next->next;
    }
    return A;
}
