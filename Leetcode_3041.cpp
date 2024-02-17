class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         map<int,int>mp;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int l1=1;
            int l2=1;
            if(mp.find(nums[i]-1)!=mp.end())
                l1=mp[nums[i]-1]+1;
            if(mp.find(nums[i])!=mp.end())
                l2=mp[nums[i]]+1;
            mp[nums[i]]=max(mp[nums[i]],l1);
            mp[nums[i]+1]=l2;
            ans=max(ans,max(l1,l2));
                
            
        }
        return ans;
    }
};
