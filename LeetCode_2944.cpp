class Solution {
public:
    int dp[1001][1001];
    int fun(int i,int d,vector<int>& prices)
    {
        if(i==prices.size())
            return 0;
        if(dp[i][d]!=-1)
            return dp[i][d];
        if(d==0)
        return dp[i][d]=fun(i+1,i+1,prices)+prices[i];
            
        return dp[i][d]=min(fun(i+1,d-1,prices),fun(i+1,i+1,prices)+prices[i]);
    }
    int minimumCoins(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return fun(0,0,prices);
    }
};
