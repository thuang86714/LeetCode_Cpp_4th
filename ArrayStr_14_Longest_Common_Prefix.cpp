#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int count = 0;
        string front = strs.front(), back = strs.back();
        int min_len = min(front.size(), back.size());
        for(int i = 0; i < min_len; i++){
            if(front[i] != back[i]){
                break;
            }
            count++;
        }

        return front.substr(0, count);
    }
};