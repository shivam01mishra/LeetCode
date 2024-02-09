class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
            map<int,long long int> preSum ;
        long sum = 0;
        long ans=-9223372036854775;

        for (int value : nums) {
             sum+=value;
            if (preSum.find(value - k)!=preSum.end()) {
               
                long long int subSum=sum-preSum[value - k]+(value-k);
            if(subSum>ans)
            ans=subSum;
                
            }
           if (preSum.find(value + k)!=preSum.end()) {
               
                long long int subSum=sum-preSum[value + k]+(value+k);
            if(subSum>ans)
            ans=subSum;
        }
        preSum[value]=preSum.find(value)==preSum.end()?sum:(preSum[value]>sum?sum:preSum[value]);
        }
        return ans== -9223372036854775 ? 0 : ans;
        
        
    }
};
