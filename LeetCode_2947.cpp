class Solution {
public:
      bool is_vowel(char c)
      {
          vector<char>v={'a','e','i','o','u'};
          for(auto i:v)
          {
            if(i==c)
                return 1;
          }
          return 0;
      }
    
    bool fun(int m, int n, int k)
    {
        if(m!=n)
            return 0;
        return (m*n)%k==0;
    }
    
    
    int beautifulSubstrings(string s, int k) {
        int n=s.length();
        vector<pair<int,int>>sum(n);
        int a=0,b=0;
        for(int i=0;i<n;i++)
        {
            if(is_vowel(s[i]))
                a++;
            else
                b++;
            sum[i]={a,b};
        }
        int ans=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(j==0)
                {
                    a=sum[i].first;
                    b=sum[i].second;
                    if(fun(a,b,k))
                        ans++;
                }
                else
                {
                    a=sum[i].first-sum[j-1].first;
                    b=sum[i].second-sum[j-1].second;
                    if(fun(a,b,k))
                        ans++;
                }
            }
        }
        return ans;
            
        
        
    }
};