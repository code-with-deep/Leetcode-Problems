class Solution{
    public : 
    int maxProduct(vector<int>& nums) {
    int maxEnd = nums[0], minEnd = nums[0], result = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0)
            swap(maxEnd, minEnd);

        maxEnd = max(nums[i], maxEnd * nums[i]);
        minEnd = min(nums[i], minEnd * nums[i]);

        result = max(result, maxEnd);
    }
    return result;
}
};




