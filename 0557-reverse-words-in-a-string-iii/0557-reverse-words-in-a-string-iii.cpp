class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string res = "";

        while (ss >> word) {
            reverse(word.begin(), word.end());

            if (!res.empty()) {
                res += " ";
            }

            res += word;
        }

        return res;
    }
};