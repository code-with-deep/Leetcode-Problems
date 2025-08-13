class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> smap;
        unordered_map<char,bool>used;
        for(int i=0; i<s.length(); i++){
            if(smap.count(s[i])){
                if(smap[s[i]] != t[i]) return false;
            }else{
                if(used.count(t[i])) return false;
                smap[s[i]] = t[i];
                used[t[i]] = true;
            }
        }

        return true;
    }
};