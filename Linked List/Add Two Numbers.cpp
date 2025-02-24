/*
2. Add Two Numbers
Solved
Medium
Topics
Companies
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode 
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* createList(vector<int>&nums)
{
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for(int num : nums)
    {
        ListNode* newNode = new ListNode(num);
        if(head == nullptr)
        {
            head = newNode;
            tail = head;
        }
        else 
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}
ListNode* addTwoNumbers(ListNode* l1,ListNode* l2)
{
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;
    int carry = 0;
    while(l1 != nullptr || l2 != nullptr || carry != 0)
    {
        int digit1 = (l1 != nullptr) ? l1->val : 0;
        int digit2 = (l2 != nullptr) ? l2->val : 0;
        
        int sum = digit1 + digit2 + carry;
        int digit = sum%10;
        carry = sum/10;
        
        ListNode* newNode = new ListNode(digit);
        temp->next = newNode;
        temp = temp->next;
        
        l1 = (l1!=nullptr) ? l1->next : nullptr;
        l2 = (l2!=nullptr) ? l2->next : nullptr;
    }
    ListNode* result = dummyNode->next;
    delete(dummyNode);
    return result;
}
void traversal(ListNode* head)
{
    ListNode* temp = head;
    while(temp != nullptr)
    {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}
int main()
{
    vector<int>nums1 = {2,4,3};
    vector<int>nums2 = {5,6,4};
    ListNode* l1 = createList(nums1);
    ListNode* l2 = createList(nums2);
    ListNode* l = addTwoNumbers(l1,l2);
    traversal(l);
}
