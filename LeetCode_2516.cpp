class Solution {
public:
    bool is_valid(vector<int>&count, int k)
    {
        if(count[0]>=k and count[1]>=k and count[2]>=k)
        {
            return 1;
        }
        return 0;
    }
    int takeCharacters(string s, int k) {
        vector<int>count(3);
        int n=s.length();
        int p1=-1;
        int p2=n;
        while(p1<n-1 and !is_valid(count,k))
        {
            count[s[++p1]-'a']++;

        }
        if(!is_valid(count,k))
        {
            return -1;
        }
        int result=p1+1;
        while(p1>=0)
        {
            count[s[p1--]-'a']--;
            while(!is_valid(count,k))
            {
                count[s[--p2]-'a']++;
            }
            result=min(result, p1+(n-p2)+1);
        }
        return result;

        
    }
};
