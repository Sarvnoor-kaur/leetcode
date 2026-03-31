class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int L = n + m - 1;

        string word(L, '?');
        vector<int> fixed(L, 0); 

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                        fixed[i + j] = 1;
                    } else {
                        return "";
                    }
                }
            }
        }

        for (int i = 0; i < L; i++) {
            if (word[i] == '?') word[i] = 'a';
        }
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bool done = false;

                    for (int j = m - 1; j >= 0; j--) {
                        int pos = i + j;

                        if (!fixed[pos]) {
                            for (char c = 'a'; c <= 'z'; c++) {
                                if (c != str2[j]) {
                                    word[pos] = c;
                                    fixed[pos] = 1; 
                                    done = true;
                                    break;
                                }
                            }
                        }
                        if (done) break;
                    }

                    if (!done) return "";
                }
            }
        }
        return word;
    }
};