/*
62. Unique Paths
Solved
Medium
Topics
Companies
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 
*/

class Solution {
    public:
    vector<vector<int>>dp;
    int countPath(int i,int j,int n,int m)
    {
        if(i==n-1 && j==m-1) return 1;
        if(i>=n || j>=m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = countPath(i+1,j,n,m) + countPath(i,j+1,n,m);
    }
    int uniquePaths(int m, int n) 
    {
        dp.resize(m,vector<int>(n,-1));
        return countPath(0,0,m,n);    
    }
};
