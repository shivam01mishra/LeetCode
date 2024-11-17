#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
     
        vector<int> result;
        int last = 0; // Tracks the last valid index based on some condition

        for (int i = 0; i < n; i++) {
            // Update `last` if the condition is met
            if ( i>0 and  nums[i] != nums[i - 1]+1) {
                last = i;
            }

            // Start adding results after we have a full window
            if (i >= k - 1) {
                if (last <= i - k + 1) {
                    result.push_back(nums[i]); // Push the current number if condition met
                } else {
                    result.push_back(-1); // Push -1 if the condition fails
                }
            }
        }

        return result;
    }
};
