class Solution {
public:
    
        int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0]+ nums[1];
        int count = 0;
        for(int i =1; i<n; i+=2){
            if(nums[i]+nums[i-1] == sum){
                count++;
            }
            else{
                return count;
            }
        }
        return count;
    }
    
};
