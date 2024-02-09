class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
       int dp[n][2];
       dp[0][0]=1;
       dp[0][1]=-1;
       int max_i=0;
       for(int i=1;i<n;i++)
       {
           dp[i][0]=1;
           dp[i][1]=-1;// it will store previous index
           for(int j=0;j<i;j++)
           {
               if(arr[i]%arr[j]==0)
               {
                   if(dp[i][0]<dp[j][0]+1)
                   {
                       dp[i][0]=dp[j][0]+1;
                       dp[i][1]=j;// update previous index
                       if(dp[i][0]>dp[max_i][0])
                       max_i=i;
                   }
               }
           }
       }
       vector<int>ans;
       while(max_i!=-1)
       {
           ans.push_back(arr[max_i]);
           max_i=dp[max_i][1];
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};
