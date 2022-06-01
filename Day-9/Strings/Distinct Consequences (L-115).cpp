//Through DP
class Solution {
public:
    int numDistinct(string s, string t) {
        int m= s.size();
        int n= t.size();
        
        vector<vector<unsigned long long>> dp(m+1, vector<unsigned long long>(n+1, 0));
        
        for(int i=0; i<=m; i++)
            dp[i][0] = 1;        
        
        
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                //if match
                if(s[i-1]==t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[m][n]; // the last element will contain the max no of subsequence.
        
    }
};

//We get TLE through this process
class Solution {
public:
    int numDistinct(string s, string t) {
        int m= s.size();
        int n= t.size();
        
        int i=0;
        int j=0;
        
        return choices(s, t, m ,n , i, j);
    }
    
    int choices(string s, string t, int m, int n, int i, int j)
    {
        //base cases
        if(j==n) return 1;
        if(i==m) return 0;
        
        if(s[i]==t[j]){
            return choices(s, t, m, n , i+1, j+1) + choices(s, t, m, n, i+1, j );
        }
        else{
            return choices(s, t, m, n, i+1, j);    
        }
    }
};
