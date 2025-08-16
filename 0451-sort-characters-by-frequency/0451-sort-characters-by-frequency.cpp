class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;   // count frequency
        }

        // Store characters with their frequencies
        vector<pair<char, int>> vec(freq.begin(), freq.end());

        // Sort by frequency in descending order
        sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        string result;
        result.reserve(s.size()); // reserve space to avoid reallocations

        // Append characters frequency times
        for (auto &[ch, count] : vec) {
            result.append(count, ch);
        }
        return result;
    }
};
