/*
Problem Description : (LC 25) HARD
-------------------------------------------------------------------------------------------
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/
//Code:
//-----------------------------------------------------------------------------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverse(ListNode *begin, ListNode *end)
    {
        ListNode *curr = begin->next;
        ListNode *first = curr;
        ListNode *prev = begin;
        ListNode *next;
        while (curr != end)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        begin->next = prev;
        first->next = curr;
        return first;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k <= 1)
            return head;
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *begin = dummyHead;
        int i = 0;
        while (head != NULL)
        {
            i++;
            if (i % k == 0)
            {
                begin = reverse(begin, head->next);
                head = begin->next;
            }
            else
            {
                head = head->next;
            }
        }
        return dummyHead->next;
    }
};