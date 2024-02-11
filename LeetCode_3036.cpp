
class Solution {
public:
    string vectorToString(const vector<int>& vec) {
        stringstream ss;
        for (int i = 0; i < vec.size(); ++i) {
            ss << vec[i];
        }
        return ss.str();
    }

    vector<int> computePrefixFunction(const string& pattern) {
        int m = pattern.size();
        vector<int> pi(m, 0);
        int k = 0;
        for (int q = 1; q < m; ++q) {
            while (k > 0 && pattern[k] != pattern[q]) {
                k = pi[k - 1];
            }
            if (pattern[k] == pattern[q]) {
                k++;
            }
            pi[q] = k;
        }
        return pi;
    }

    int countOccurrences(const string& text, const string& pattern) {
        int n = text.size();
        int m = pattern.size();
        vector<int> pi = computePrefixFunction(pattern);
        int q = 0;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            while (q > 0 && pattern[q] != text[i]) {
                q = pi[q - 1];
            }
            if (pattern[q] == text[i]) {
                q++;
            }
            if (q == m) {
                count++;
                q = pi[q - 1];
            }
        }
        return count;
    }

    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        vector<int> v;
        for(int i=0;i<pattern.size();i++)
            pattern[i]++;
        for (int i = 1; i < nums.size(); i++) {
            int temp;
            if (nums[i] > nums[i - 1])
                temp = 2;
            if (nums[i] == nums[i - 1])
                temp = 1;
            if (nums[i] < nums[i - 1])
                temp = 0;
            v.push_back(temp);
        }
        string s1 = vectorToString(v);
        string s2 = vectorToString(pattern);
        return countOccurrences(s1, s2);
    }
};
