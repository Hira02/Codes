/*
Problem Description : (LC 61)
-----------------------------------------------------------------------------------------
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
*/
//Code:
//---------------------------------------------------------------------------------------
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
    int getListLength(ListNode *head)
    {
        int count = 0;
        while (head)
        {
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return NULL;

        int len = getListLength(head);
        if (k > len)
            k = k % len;
        if (k == 0 || k == len)
            return head;
        int count = 1;
        ListNode *curr = head;
        int toMove = len - k;
        ListNode *newTail = head;
        while (curr->next != NULL) // tail node can be found while finding the length of the list
        {
            curr = curr->next;
            count++;
            if (count == toMove)
                newTail = curr;
        }
        ListNode *newHead = newTail->next;
        newTail->next = NULL;
        curr->next = head;
        return newHead;
    }
};
//TC : O(n)+O(n)