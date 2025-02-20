/*
46. Permutations
Solved
Medium
Topics
Companies
Given an array nums of distinct integers, return all the possible 
permutations
. You can return the answer in any order.
Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
*/
#include<bits/stdc++.h>
using namespace std;
void backtrack(vector<int>&nums,vector<vector<int>>&result,int start)
{
    if(start == nums.size())
    {
        result.push_back(nums);
        return;
    }
    for(int i=start;i<nums.size();i++)
    {
        swap(nums[start],nums[i]);
        backtrack(nums,result,start+1);
        swap(nums[start],nums[i]);
    }
}
vector<vector<int>>permute(vector<int>&nums)
{
    vector<vector<int>>result;
    backtrack(nums,result,0);
    return result;
}
int main()
{
    vector<int>nums = {1,2,3};
    vector<vector<int>>result = permute(nums);
    for(auto i : result)
    {
        cout<<"[ ";
        for(auto j : i)
        {
            cout<<j<<" ";
        }
        cout<<"]"<<endl;
    }

}
/*
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        do 
        {
            vector<int>arr;
            for(int num : nums)
            {
                arr.push_back(num);
            }
            result.push_back(arr);
        }while(next_permutation(nums.begin(),nums.end()));
        return result; 
    }
};
*/
