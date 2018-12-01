class Solution {
public:
    /**
     * @param s: a string,  encoded message
     * @return: an integer, the number of ways decoding
     */
    int numDecodings(string &s) {
        // write your code here
        if(s.size() == 0 || (s.size() > 1 && s[0] == '0'))
            return 0;
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0:1;
        for(int i = 2; i <= n; ++i)
        {
            int n1 = stoi(s.substr(i-1,1));
            int n2 = stoi(s.substr(i-2, 2));
            if(n1 != 0)
                dp[i] += dp[i-1];
            if(n2 > 9 && n2 <= 26)
                dp[i] += dp[i-2];
        }
        return dp[n];
    }
};
