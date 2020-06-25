/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode *mergeBothHalfs(ListNode *A, ListNode *B)
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
    }
    if (B != NULL)
    {
        curr->next = B;
    }
    return head;
}
ListNode *findMiddle(ListNode *A)
{
    ListNode *slow = A, *fast = A, *prev = NULL;
    while (slow && fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev)
        prev->next = NULL;
    return slow;
}
void mergeSort(ListNode **A)
{
    ListNode *head = *A;
    if (head && head->next)
    {
        ListNode *first_half = head;
        ListNode *second_half = findMiddle(head);
        mergeSort(&first_half);
        mergeSort(&second_half);
        *A = mergeBothHalfs(first_half, second_half);
    }
}
ListNode *Solution::sortList(ListNode *A)
{
    mergeSort(&A);
    return A;
}
