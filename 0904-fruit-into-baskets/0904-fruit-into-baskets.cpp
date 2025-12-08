class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        unordered_map<int,int> mp;
        int low = 0, result = 0;

        for(int high = 0; high < fruits.size(); high++) {

            // include current fruit
            mp[fruits[high]]++;

            // shrink window if more than 2 fruit types
            while(mp.size() > 2){
                mp[fruits[low]]--;
                if(mp[fruits[low]] == 0) {
                    mp.erase(fruits[low]);
                }
                low++;
            }

            // calculate window size
            int length = high - low + 1;

            if(length > result){
                result = length;
            }
        }

        return result;
    }
};
