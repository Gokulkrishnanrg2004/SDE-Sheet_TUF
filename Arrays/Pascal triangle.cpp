/*
118. Pascal's Triangle
Solved
Easy
Topics
Companies
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]

*/

class Solution {
    public:
    int getval(int n,int k)
    {
        int res = 1;
        if(k > n - k)
        {
            k = n - k;
        }
        for(int i=0;i<k;i++)
        {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }
    vector<vector<int>> generate(int n) 
    {
        vector<vector<int>>mat;
        for(int row=0;row<n;row++)
        {
            vector<int>arr;
            for(int i=0;i<=row;i++)
            {
                arr.push_back(getval(row,i));
            }
            mat.push_back(arr);
        }
        return mat;
    }
};
