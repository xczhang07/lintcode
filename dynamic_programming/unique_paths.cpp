class Solution {
public:
    /**
     * @param m: positive integer (1 <= m <= 100)
     * @param n: positive integer (1 <= n <= 100)
     * @return: An integer
     */
    int uniquePaths(int m, int n) {
        // write your code here
        if(m == 0 || n == 0) return 0;
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i)
            matrix[i][0] = 1;
        for(int i = 0; i < n; ++i)
            matrix[0][i] = 1;
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1]; 
        }
        return matrix[m-1][n-1];
    }
};
