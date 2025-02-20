/*
Largest subarray with 0 sum
Difficulty: MediumAccuracy: 41.84%Submissions: 384K+Points: 4Average Time: 20m
Given an array arr containing both positive and negative integers, the task is to compute the length of the largest subarray that has a sum of 0.

Examples:

Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: The largest subarray with a sum of 0 is [-2, 2, -8, 1, 7].
Input: arr[] = [2, 10, 4]
Output: 0
Explanation: There is no subarray with a sum of 0.
Input: arr[] = [1, 0, -4, 3, 1, 0]
Output: 5
Explanation: The subarray is [0, -4, 3, 1, 0].
  */
class Solution {
  public:
    int maxLen(vector<int>& arr) 
    {
        unordered_map<int,int>mp;
        int maxlen = 0;
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum += arr[i];
            if(sum == 0)
            {
                maxlen = i+1;
            }
            else 
            {
                if(mp.find(sum) != mp.end())
                {
                    maxlen = max(maxlen, i - mp[sum]);
                }
                else 
                {
                    mp[sum] = i;
                }
            }
        }
        return maxlen;
    }
};
