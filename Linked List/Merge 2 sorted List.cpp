/*
21. Merge Two Sorted Lists
Solved
Easy
Topics
Companies
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode* createList(vector<int>& nums)
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
ListNode* mergeList(ListNode* l1,ListNode* l2)
{
    ListNode* dummyNode = new ListNode(0);
    ListNode* current = dummyNode;
    ListNode* temp1 = l1;
    ListNode* temp2 = l2;
    
    while(temp1 != nullptr && temp2!=nullptr)
    {
        if(temp2->val <= temp1->val)
        {
            current->next = temp2;
            temp2 = temp2->next;
            current = current->next;
        }
        else
        {
            current->next = temp1;
            temp1 = temp1->next;
            current = current->next;
        }
    }
    if(temp1 != nullptr)
    {
        current->next = temp1;
    }
    if(temp2 != nullptr)
    {
        current->next = temp2;
    }
    return dummyNode->next;
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
    vector<int>nums1 = {1,4,5};
    vector<int>nums2 = {1,3,4};
    ListNode* l1 = createList(nums1);
    ListNode* l2 = createList(nums2);
    ListNode* l = mergeList(l1,l2);
    traversal(l);
}
