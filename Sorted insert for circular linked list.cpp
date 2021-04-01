/*
Problem Description : https://practice.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1/?company[]=Microsoft&company[]=Microsoft&problemStatus=unsolved&problemType=functional&difficulty[]=-2&difficulty[]=-1&difficulty[]=0&page=1&sortBy=submissions&query=company[]MicrosoftproblemStatusunsolvedproblemTypefunctionaldifficulty[]-2difficulty[]-1difficulty[]0page1sortBysubmissionscompany[]Microsoft#
------------------------------------------------------------------------------------------------------------------------------------------------------
Given a sorted circular linked list, the task is to insert a new node in this circular list so that it remains a sorted circular linked list.

Example 1:

Input:
LinkedList = 1->2->4
(the first and last node is connected,
i.e. 4 --> 1)
data = 2
Output: 1 2 2 4
Example 2:

Input:
LinkedList = 1->4->7->9
(the first and last node is connected,
i.e. 9 --> 1)
data = 5
Output: 1 4 5 7 9
Your Task:
The task is to complete the function sortedInsert() which should insert the new node into the given circular linked list and return the head of the linkedlist.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
0 <= N <= 105
*/
//Code:
//----------------------------------------------------------------------------------------------------------------------------------------------
Node *sortedInsert(Node* head, int data)
    {
       //Your code here
       struct Node* curr = head;
       struct Node* newNode = new Node(data);
       if(curr == NULL){
           newNode->next = newNode;
           head = newNode;
       }else if(curr->data>= newNode->data){
           while(curr->next != head){
               curr = curr->next;
           }
           curr->next = newNode;
           newNode->next = head;
           head = newNode;
       }else {
           while(curr->next != head && curr->next->data<= newNode->data)
                curr = curr->next;
               newNode->next = curr->next;
               curr->next = newNode;
           }
    //   }
       return head;
    //   return head;
    }
