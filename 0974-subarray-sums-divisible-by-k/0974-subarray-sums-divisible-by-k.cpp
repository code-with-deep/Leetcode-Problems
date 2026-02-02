class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int, int> f;
        f[0] = 1;   // base case

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            int rem = sum % k;
            if (rem < 0) rem += k;  // handle negative modulo

            if (f.find(rem) != f.end()) {
                res += f[rem];
            }

            f[rem]++;
        }

        return res;
    }
};
