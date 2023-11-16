class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<int>st;
        int n=nums.size();
        for(auto s:nums)
        {
            bitset<16>bits(s);
            int number=bits.to_ulong();
            st.insert(number);
        }
        string ans;
        for(int i=0;i<17;i++)
        {
            if(st.find(i)==st.end())
            {
               bitset<16>result(i);
               ans=result.to_string();
               break;
            }
        }
        return ans.substr(16-n,n);
    }
};