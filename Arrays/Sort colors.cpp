/*
75. Sort Colors
Solved
Medium
Topics
Companies
Hint
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
*/
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]== 0)
            {
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};


/*
#include<bits/stdc++.h>
using namespace std;
void sortColor(vector<int>& arr)
{
    int left = 0;
    int mid = 0;
    int right = arr.size()-1;
    while(mid <= right)
    {
        if(arr[mid] == 0)
        {
            swap(arr[left],arr[mid]);
            mid++;
            left++;
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else if(arr[mid] == 2)
        {
            swap(arr[right],arr[mid]);
            right--;
        }
    }
}
int main()
{
    vector<int>nums = {2,0,2,1,1,0};
    sortColor(nums);
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
    
}
*/
