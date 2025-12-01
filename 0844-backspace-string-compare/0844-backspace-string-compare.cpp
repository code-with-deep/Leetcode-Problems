class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1;
        int j = t.size() - 1;
        int skipS = 0, skipT = 0;
        
        while (i >= 0 || j >= 0) {

            // Process string s
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++;
                    i--;
                } else if (skipS > 0) {
                    skipS--;
                    i--;
                } else {
                    break;
                }
            }

            // Process string t
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++;
                    j--;
                } else if (skipT > 0) {
                    skipT--;
                    j--;
                } else {
                    break;
                }
            }

            // Compare characters (if both valid positions)
            if (i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }

            // If one string ended before the other
            if ((i >= 0) != (j >= 0)) {
                return false;
            }

            i--;
            j--;
        }

        return true;
    }
};
