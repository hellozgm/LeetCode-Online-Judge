//方法1，动态规划，dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]，再考虑一下边界问题，时间复杂度和空间复杂度都是O(m*n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > dp(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0){
                    if(j == 0)
                        dp[i][j] = grid[i][j];
                    else
                        dp[i][j] = dp[i][j-1] + grid[i][j];
                }
                else{
                    if(j == 0)
                        dp[i][j] = dp[i-1][j] + grid[i][j];
                    else
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};

//方法2： 优化空间复杂度为O(n)，其实每次循环的时候前面一层的i-1位置可以省略的，变成现在一层新旧更新。
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0){
                    if(j == 0)
                        dp[j] = grid[i][j];
                    else
                        dp[j] = dp[j-1] + grid[i][j];
                }
                else{
                    if(j == 0)
                        dp[j] = dp[j] + grid[i][j];
                    else
                        dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
                }
            }
        }
        return dp[n-1];
    }
};
