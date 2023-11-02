#include <stack>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    int calculate(string s) {
      //credit to d40a and opedashila and jacklee20499
      //TC O(s.size()), SC (n) where n is the number of digits
        stack<int> op;
        op.push(1);
        int res = 0, sign = 1, num = 0;
        for(char &c:s){
            if(isdigit(c)){
                num = num*10 + (c - '0');
            }else{
                res += num*sign*op.top();
                num = 0;
                if(c == '+'){
                  sign = 1;
                }else if(c == '-'){
                  sign = -1;
                }else if(c == ')'){
                  op.pop();
                }else if(c == '('){
                  op.push(op.top()*sign);
                  sign = 1;
                }
            }
        }
      //handle the last digit
        res += num*sign;
        return res;
    }
};