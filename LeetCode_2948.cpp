class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        vector<int>v1;
        vector<int>v2;
        v1.push_back(v[0].first);
        v2.push_back(v[0].second);
        for(int i=1;i<nums.size();i++)
        {
            if(v[i].first-v1.back()<=limit)
            {
                v1.push_back(v[i].first);
                v2.push_back(v[i].second);
            }
            else
            {
                sort(v1.begin(),v1.end());
                sort(v2.begin(),v2.end());
                for(int j=0;j<v1.size();j++)
                {
                    int inx=v2[j];
                    int val=v1[j];
                    nums[inx]=val;
                }
                v1.clear();
                v1.push_back(v[i].first);
                v2.clear();
                v2.push_back(v[i].second);
            }
        }
         sort(v1.begin(),v1.end());
                sort(v2.begin(),v2.end());
                for(int j=0;j<v1.size();j++)
                {
                    int inx=v2[j];
                    int val=v1[j];
                    nums[inx]=val;
                }
        return nums;
        
    }
};