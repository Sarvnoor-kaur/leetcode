class Solution {
public:
    int minLength(string s) {
        while (s.find("AB") != string::npos || s.find("CD") != string::npos) {

            int pos = s.find("AB");
            if (pos != string::npos)
                s.erase(pos, 2);

            pos = s.find("CD");
            if (pos != string::npos)
                s.erase(pos, 2);
        }
        return s.size();
    }
};