class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        map<int,int>mp;
        int m=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
          mp[nums[i]]++;
            m=max(m,mp[nums[i]]);
        }
       int x = (*min_element(nums.begin(), nums.end()));
        for(int i:nums)
        {
            if(i%x)
                return 1;
        }
         return (mp[x]+1)/2;
        
    }
};
