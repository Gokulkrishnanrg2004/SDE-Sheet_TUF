/*
53. Maximum Subarray
Solved
Medium
Topics
Companies
Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
  */
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum=0;
        int maxsum = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            if(maxsum < sum)
            {   
                maxsum = sum;
            }
            if(sum<0)
            {
                sum=0;
            }
        }
        return maxsum;
    }
};

/*
#include<bits/stdc++.h>
using namespace std;
int subarray(vector<int>& nums)
{
    int maxSum = 0,sum=0;
    for(int i=0;i<nums.size();i++)
    {
        sum=0;
        for(int j=0;j<nums.size();j++)
        {
            sum += nums[j];
            if(sum < 0)
            {
                sum = 0;
            }
            else if(sum > maxSum)
            {
                maxSum = max(maxSum,sum);
            }
        }
    }
    return maxSum;
}
int main()
{
    vector<int>nums = {5,4,-1,7,8};
    int maxSum = subarray(nums);
    cout<<maxSum;
}
*/
