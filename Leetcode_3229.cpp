class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long int result=0;
        long long int prev_dif;
        for(int i=0;i<target.size();i++)
        {
            long long int cur_dif=nums[i]-target[i];
            if(result==0 or prev_dif*cur_dif<0)
            result+=abs(cur_dif);
            else{
                if(abs(cur_dif)>abs(prev_dif))
                result+=(abs(cur_dif)-abs(prev_dif));
            }
            prev_dif=cur_dif;
        }
        return result;
        
    }
};
