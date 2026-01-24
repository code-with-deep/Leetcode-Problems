class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int keep = arr[0];        // max subarray sum ending here without deletion
        int deleteOne = arr[0];  // max subarray sum ending here with one deletion
        int ans = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            deleteOne = max(deleteOne + arr[i], keep);
            keep = max(keep + arr[i], arr[i]);
            ans = max({ans, keep, deleteOne});
        }

        return ans;
    }
};
