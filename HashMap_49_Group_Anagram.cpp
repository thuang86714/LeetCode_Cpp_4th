#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //credit to jianchao-li and guangqianpeng
        unordered_map<string, vector<string>> map;
        //traverse all strings in strs, and sort every string to map
        for(auto& s:strs){
            string word = s;
            sort(word.begin(), word.end());
            map[word].push_back(s);
        }

        vector<vector<string>> res;
        res.reserve(map.size());

        for(auto &it:map){
            res.push_back(move(it.second));
        }

        return res;
    }
};