/*
Problem Description : (Lc 147)
------------------------------------------------------------------------------------
Sort a linked list using insertion sort.


A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
 

Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within 
the sorted list, and inserts it there.
It repeats until no input elements remain.

Example 1:
https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif
Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/
//Code:
//-----------------------------------------------------------------------------------------------------------------
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
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)
            return NULL;
       ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = head;
        ListNode* prev = dummy;
        while(curr){
            if(curr->next && curr->next->val<curr->val){
                while(prev->next && prev->next->val <curr->next->val){
                    prev = prev->next;
                }
                ListNode* temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = temp;
                prev = dummy;
            }else{
                curr = curr->next;
            }
        }
        return dummy->next;
        
    }
};