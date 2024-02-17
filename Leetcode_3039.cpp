class Solution {
public:
    string lastNonEmptyString(string s) {
        map<char,int>mp;
        int m=0;
        for(auto c:s)
        {
            mp[c]++;
            m=max(m,mp[c]);
        }
        string ans="";
        for(int i=s.length()-1;i>=0;i--)
        {
            if(mp[s[i]]==m)
            {
                ans=s[i]+ans;
                mp[s[i]]=0;
            }
        }
        return ans;
    }
};
