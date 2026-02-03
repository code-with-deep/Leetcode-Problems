class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0 , zero = 0, one = 0, res = 0;
        unordered_map<int,int>f;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                zero++;
            }
            else{
                one++;
            }
            int diff = zero - one;
            if(diff == 0){
                res = max(res,i+1);
                continue;
            }
            if(f.find(diff) == f.end()){
               f[diff] = i; 
            }else{
                int idx = f[diff];
                int len = i - idx;
                res = max(len,res);
            }
        }
        return res;
    }
};