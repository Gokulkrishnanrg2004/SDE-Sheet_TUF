/*
128. Longest Consecutive Sequence
Solved
Medium
Topics
Companies
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
Example 3:

Input: nums = [1,0,1,2]
Output: 3
 
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.empty()) return 0;
        
        int count = 1, maxlen = 1; // Start with 1 as the sequence count
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue; // Skip duplicates
            }
            if (nums[i] - nums[i - 1] == 1) {
                // If consecutive, increase count
                count++;
            } else {
                // Reset count when the sequence breaks
                maxlen = max(maxlen, count);
                count = 1; // Reset count for the next sequence
            }
        }
        
        // Update maxlen in case the longest sequence ends at the last element
        maxlen = max(maxlen, count);
        
        return maxlen; // Return the longest sequence length
    }
};
