class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int low = 0;       // Left pointer of sliding window
        int high = 0;      // Right pointer of sliding window
        int sum = 0;       // Current sum of the sliding window
        int result = INT_MAX; // Store minimum length of valid subarray

        // Expand the window using high pointer
        while (high < n) {
            sum += nums[high];  // Add current element to the window sum

            // When window sum becomes >= target,
            // shrink the window from left to find the minimum length
            while (sum >= target) {
                // Update minimum length
                result = min(result, high - low + 1);

                // Remove nums[low] from sum and move low forward
                sum -= nums[low];
                low++;
            }

            // Move high forward to expand window
            high++;
        }

        // If result was never updated, no valid subarray exists → return 0
        return (result == INT_MAX ? 0 : result);
    }
};
