class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        int sum[n];
        sum[0]=nums[0];
        for(int i=1;i<n;i++)
        sum[i]=sum[i-1]+nums[i];

        vector<int>result(n);
        for(int i=0;i<n;i++)
        {           
           int left_dif=0;
           if(i>0)
           left_dif=(i*nums[i]-sum[i-1]);
           int right_dif=(sum[n-1]-sum[i])-(n-i-1)*nums[i];
           result[i]=left_dif+right_dif; 
        } 
        return result;
    }
};