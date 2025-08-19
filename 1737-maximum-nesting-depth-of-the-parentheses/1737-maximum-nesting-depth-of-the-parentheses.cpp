class Solution {
public:
    int maxDepth(string s) {
        int currentOpen = 0;
        int maxOpen = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                currentOpen++;
            } else if (s[i] == ')') {
                currentOpen--;
            }
            maxOpen = std::max(maxOpen, currentOpen); // use std::max in C++
        }
        return maxOpen;
    }
};
