#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size() - 1, n = b.size() - 1;
        int sum = 0;
        string res = "";
        while(m >= 0|| n >= 0){
            if(m >= 0)sum += a[m--] - '0';
            if(n >= 0)sum += b[n--] - '0';

            res = res + to_string(sum%2);
            sum /= 2;
        }
        if(sum){
            res = res + to_string(sum);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};