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
ListNode* reverse(ListNode* head)
{
    ListNode* prev = nullptr;
    ListNode* temp = head;
    while(temp != nullptr)
    {
        ListNode* nextl = temp->next;
        temp->next = prev;
        prev = temp;
        temp = nextl;
    }
    return prev;
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
    ListNode* l1 = createList(nums1);
    ListNode* l = reverse(l1);
    traversal(l);
}
