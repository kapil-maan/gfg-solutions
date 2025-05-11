//medium

class Solution {
  public:
    string maxNum;

    void helper(string& s, int k, int idx) {
        if (k == 0) return;

        char maxDigit = *max_element(s.begin() + idx, s.end());
        if (maxDigit != s[idx]) k--;

        for (int j = s.size() - 1; j >= idx; --j) {
            if (s[j] == maxDigit) {
                swap(s[idx], s[j]);
                if (s > maxNum) maxNum = s;
                helper(s, k, idx + 1);
                swap(s[idx], s[j]); // backtrack
            }
        }
    }

    string findMaximumNum(string& s, int k) {
        maxNum = s;
        helper(s, k, 0);
        return maxNum;
    }
};