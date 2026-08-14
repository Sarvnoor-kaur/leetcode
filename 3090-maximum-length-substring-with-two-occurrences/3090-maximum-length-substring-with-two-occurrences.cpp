class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> count;
        
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {
            count[s[right]]++;

            while (count[s[right]] > 2) {
                count[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};