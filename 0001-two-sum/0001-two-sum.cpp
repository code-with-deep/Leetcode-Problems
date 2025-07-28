class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int tar) {
        unordered_map<int, int> a;  // Use 'a' consistently instead of 'm'
        vector<int> ans;

        for (int i = 0; i < arr.size(); i++) {
            int first = arr[i];
            int sec = tar - first;

            if (a.find(sec) != a.end()) {
                ans.push_back(a[sec]);  // Store the previous index first
                ans.push_back(i);
                return ans;  // Return immediately after finding the pair
            }

            a[first] = i;  // Store the index of the current number
        }
        
        return ans;  // If no pair is found, return an empty vector
    }
};