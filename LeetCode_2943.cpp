class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        int max1=1;
        
        int count=0;
        for(int i=0;i<h.size();i++)
        {
           if(i==0 or h[i]!=h[i-1]+1)
               count=2;
            else
            count++;
            max1=max(max1,count);
        }
        
          int max2=1;
        
        
        for(int i=0;i<v.size();i++)
        {
           if(i==0 or v[i]!=v[i-1]+1)
               count=2;
            else
            count++;
            max2=max(max2,count);
        }
        //cout<<max1<<" "<<max2<<endl;
        return pow(min(max1,max2),2);
        
        
    }
};