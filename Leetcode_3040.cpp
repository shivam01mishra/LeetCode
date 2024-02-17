class Solution {
public:
    int dp[2001][2001];
    // vector<int> v;
   int fun(int i, int j,int prev, vector<int> &v)
    {
        if(j-i<=0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int temp=0;
        if(v[i]+v[i+1]==prev)
            temp=max(temp,1+fun(i+2,j,prev,v));
         if(v[j]+v[j-1]==prev)
            temp=max(temp,1+fun(i,j-2,prev,v));
         if(v[i]+v[j]==prev)
            temp=max(temp,1+fun(i+1,j-1,prev,v));
        return dp[i][j]=temp;
    }
    int maxOperations(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof dp);
        int a = fun(2,n-1,nums[0]+nums[1],nums);
        memset(dp,-1,sizeof dp);
        int b = fun(0,n-3,nums[n-1]+nums[n-2],nums);
        memset(dp,-1,sizeof dp);
        
        
        return 1+max(a,max(b,fun(1,n-2,nums[0]+nums[n-1],nums)));
        
        
    }
};
