/*
Problem Description : https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1/?company[]=Amazon&company[]=Amazon&problemType=functional&page=1&sortBy=submissions&query=company[]AmazonproblemTypefunctionalpage1sortBysubmissionscompany[]Amazon#
------------------------------------------------------------------------------------------------------------------------------------------------
Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.

Example 1:

Input:
N = 2
LinkedList: 1->2->3->4->5->6->7->8->9
Output: 8
Explanation: In the first example, there
are 9 nodes in linked list and we need
to find 2nd node from end. 2nd node
from end os 8.  
Example 2:

Input:
N = 5
LinkedList: 10->5->100->5
Output: -1
Explanation: In the second example, there
are 4 nodes in the linked list and we
need to find 5th from the end. Since 'n'
is more than the number of nodes in the
linked list, the output is -1.
Your Task:
The task is to complete the function getNthFromLast() which takes two arguments: reference to head and N and you need to return Nth from the end or -1 in case 
node doesn't exist..

Note:
Try to solve in single traversal.

Expected Time Complexity: O(N).

*/
//Code:
//-------------------------------------------------------------------------------------------------------------------------------------------
int getNthFromLast(Node *head, int n)
{
       // Your code here
       Node* mainPtr = head;
       Node* refPtr = head;
       int count = 0;
       if(head){
           while(count<n){
               if(refPtr == NULL){
                   return -1;
               }
               refPtr = refPtr->next;
               count++;
           }
       }
       if(refPtr == NULL){
           return mainPtr->data;
       }
       while(refPtr){
           mainPtr = mainPtr->next;
           refPtr = refPtr->next;
       }
       return mainPtr->data;
}
Expected Auxiliary Space: O(1).

Constraints:
1 <= L <= 103
1 <= N <= 103
