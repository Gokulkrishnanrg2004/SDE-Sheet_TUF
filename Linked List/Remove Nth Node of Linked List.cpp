/*
19. Remove Nth Node From End of List
Solved
Medium
Topics
Companies
Hint
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=1;i<=n;i++)
        {
            fast = fast->next;
        }
        // Edge case if the input is
        // head = [1,2,3], n = 3 such that we need to remove 1 so that we return head->next
        if(fast==nullptr)
        {
            return head->next;
        }
        while(fast->next!=nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete(temp);
        return head;


    }
};
