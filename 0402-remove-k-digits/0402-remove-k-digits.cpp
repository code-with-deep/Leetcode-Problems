class Solution {
public:
    string removeKdigits(string num, int k) {
        string stack = "";
        
        for (char digit : num) {
            while (!stack.empty() && stack.back() > digit && k > 0) {
                stack.pop_back();
                k--;
            }
            stack.push_back(digit);
        }

        // If still k left, remove from the end
        while (k > 0 && !stack.empty()) {
            stack.pop_back();
            k--;
        }

        // Remove leading zeros
        int i = 0;
        while (i < stack.size() && stack[i] == '0') i++;

        string result = stack.substr(i);
        return result.empty() ? "0" : result;
    }
};
