class Solution {
public:
    bool canSortArray(std::vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && (__builtin_popcount(nums[i]) == __builtin_popcount(nums[j])))
                j++;
            std::sort(nums.begin() + i, j == n ? nums.end() : nums.begin() + j);
            i = j;
        }

        for (int i = 1; i < n; i++)
            if (nums[i] < nums[i - 1])
                return false;

        return true;
    }
};
