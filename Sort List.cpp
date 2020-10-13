/*
Problem Description : (LC 148)
--------------------------------------------------------------------------------------------------
Given the head of a linked list, return the list after sorting it in ascending order.

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

 

Example 1:

https://assets.leetcode.com/uploads/2020/09/14/sort_list_1.jpg
Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:

https://assets.leetcode.com/uploads/2020/09/14/sort_list_2.jpg
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105
*/
//Code:
//-------------------------------------------------------------------------------------------------------------------------------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode* result = NULL;
        if(a == NULL)
            return b;
       else if(b == NULL)
            return a;
        if(a->val<=b->val){
            result = a;
            result->next = merge(a->next, b);
        }
        else{
            result = b;
            result->next = merge(a, b->next);
        }
        return result;
    }
    void frontBackSplit(ListNode* head, ListNode** a, ListNode** b){
        ListNode* fast = head->next;
        ListNode* slow = head;
        ListNode* prev;
        while(fast){
            fast = fast->next;
                if(fast){
            // prev = slow;
            slow = slow->next;
            fast = fast->next;
                }
        }
        
        *a = head;
            *b = slow->next;
            slow->next = NULL;
        
    }
   void mergeSort(ListNode** head){
        
        ListNode* headRef = *head;
       if((headRef == NULL) || (headRef->next == NULL))
            return ;
        ListNode* a;
        ListNode* b;
        frontBackSplit(headRef, &a, &b);
        mergeSort(&a);
        mergeSort(&b);
       *head = merge(a,b);
    
}
ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
    // ListNode* headRef = head;
    mergeSort(&head);
    return head;
    }
};
