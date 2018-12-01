class Solution {
public:
    /**
     * @param costs: n x 3 cost matrix
     * @return: An integer, the minimum cost to paint all houses
     */
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        if(costs.size() == 0 || costs[0].size() == 0)
            return 0;
        int m = costs.size();
        int n = costs[0].size();
        vector<vector<int>> dp(m, vector<int>(3,0));
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];
        for(int i = 1; i < costs.size(); ++i)
        {
            dp[i][0] = costs[i][0] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = costs[i][1] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = costs[i][2] + min(dp[i-1][0], dp[i-1][1]);
        }
        
        return min(dp[m-1][0], min(dp[m-1][1], dp[m-1][2]));
    }
};
