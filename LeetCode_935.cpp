class Solution {
    int table[4][3]={1,2,3,4,5,6,7,8,9,-1,0,-1};
    int row[8]={2,2,-2,-2,1,1,-1,-1};
    int col[8]={1,-1,1,-1,2,-2,2,-2};
    int mod=1e9+7;
public:
    int dp[4][3][5001];
    long long int fun(int i, int j, int n)
    {
        if(i<0 or i>=4 or j<0 or j>=3 or table[i][j]==-1)
        return 0;
        if(n==1)
        return 1;
        if(dp[i][j][n]!=-1)
        return dp[i][j][n];
        int sum=0;
       for(int k=0;k<8;k++)
       sum=(sum+fun(i+row[k],j+col[k],n-1))%mod;
       return dp[i][j][n]=sum;
    }
    int knightDialer(int n) {
        int sum=0;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<10;i++)
        sum=(sum+fun(i/3,i%3,n))%mod;
        return (sum+fun(3,1,n))%mod;
    }
};