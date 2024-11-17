#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n - 1;

        // Find the leftmost sorted part
        while (l + 1 < n && arr[l] <= arr[l + 1]) {
            l++;
        }

        // If the entire array is already sorted
        if (l == n - 1) {
            return 0;
        }

        // Find the rightmost sorted part
        while (r - 1 >= 0 && arr[r - 1] <= arr[r]) {
            r--;
        }

        // Calculate the minimum length of the subarray to remove
        int ans = min(n - l - 1, r); // Removing either the left or the right part

        // Try merging the two sorted parts
        for (int i = 0; i <= l; i++) {
            int j = lower_bound(arr.begin() + r, arr.end(), arr[i]) - arr.begin();
            ans = min(ans, j - i - 1);
        }

        return ans;
    }
};
