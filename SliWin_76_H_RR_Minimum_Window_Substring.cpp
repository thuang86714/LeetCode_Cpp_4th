#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        //credit to jacklee20499, TC O(m*n), SC O(1)
        //edge case check
        if(s.size() < t.size()){
            return "";
        }
        int start, len = 10e6, count = t.size();
        vector<int> map(128, 0);//use vector as map
        for(int i = 0; i < count; i++){
            map[t[i]]++;
        }

        int l = 0, r = 0;
        for(; r < s.size(); r++){
            if(map[s[r]] > 0){//that's why we use vector instead of hash map
                count--;
            }
            map[s[r]]--;

            while(count == 0){
                if(len > r - l + 1){
                    len = r - l + 1;
                    start = l;
                }
                
                map[s[l]]++;
                if(map[s[l]] > 0){
                    count++;
                }
                l++;
            }
        }

        if(len == 10e6){
            return "";
        }else{
            return s.substr(start, len);
        }
    }
};