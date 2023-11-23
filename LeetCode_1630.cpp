class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool>ans;
        for(int i=0;i<l.size();i++)
        {
            vector<int>temp(nums.begin()+l[i],nums.begin()+r[i]+1);
            sort(temp.begin(),temp.end());
            int j;
            for(j=2;j<temp.size();j++)
            {
                if(temp[j-2]-temp[j-1]!=temp[j-1]-temp[j])
                {
                    ans.push_back(0);
                    break;
                }
            }
              if(j>=temp.size() )
                ans.push_back(1);
        }
        return ans;
    }
};