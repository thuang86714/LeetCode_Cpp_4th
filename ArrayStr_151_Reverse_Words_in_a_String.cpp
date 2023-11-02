#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> tempVec;
        string res = "";
        for(int i = 0; i < s.size(); i++){
            if(!isalnum(s[i])){
                continue;
            }

            string temp = "";
            while(i < s.size() && isalnum(s[i])){
                temp += s[i];
                i++;
            }
            tempVec.push_back(temp);

        }
        //handle the last word

        //reverse and get res
        reverse(tempVec.begin(), tempVec.end());
        for(string str:tempVec){
            res = res + str + " ";
        }
        res.pop_back();
        return res;
    }
};