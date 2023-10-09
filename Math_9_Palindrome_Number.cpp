#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x > 0 && x%10 == 0))return false;

        int sum = 0;
        while(x > sum){
            sum = sum*10 + x%10;
            x /= 10;
        }

        return (x == sum) || (sum/10 == x);
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)return false;
        string temp = to_string(x);

        int l = 0, r = temp.size()-1;
        while(l <= r){
            if(temp[l] != temp[r])return false;
            l++;
            r--;
        }
        return true;
    }
};