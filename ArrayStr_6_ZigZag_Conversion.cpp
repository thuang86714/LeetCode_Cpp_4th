#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }
        vector<string> tempVec(numRows);
        int j = 0, dir = -1;
        for(char c:s){
            if(j == 0 || j == numRows -1){
                dir *= -1;
            }
            tempVec[j] += c;
            j += dir;
        }

        string res = "";
        for(string str:tempVec){
            res += str;
        }

        return res;
    }
};