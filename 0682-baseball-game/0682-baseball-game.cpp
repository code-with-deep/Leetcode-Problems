class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stack;
        int total = 0; 

        for (const string& op : operations) {
            if (op == "C") {
                if (!stack.empty()) {
                    total -= stack.back();
                    stack.pop_back();
                }
            }
            else if (op == "D") {
                int val = stack.back() * 2;
                stack.push_back(val);
                total += val;
            }
            else if (op == "+") {
                int val = stack[stack.size() - 1] + stack[stack.size() - 2];
                stack.push_back(val);
                total += val;
            }
            else { 
                int val = stoi(op);
                stack.push_back(val);
                total += val;
            }
        }

        return total;
    }
};
