class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string,int>mp;
        int result=0;
        for(auto &v : matrix)
        {
            string s="1";
            int n=v.size();
            for(int i=1;i<n;i++)
            {
                if(v[i]==v[i-1])
                {
                    s+=s.back();
                }
                else
                {
                    s+=s.back()=='1'?'0':'1';
                }
            }
            mp[s]++;
            result=max(mp[s],result);
        }
        return result;
        
    }
};
