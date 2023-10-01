/*
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "1 + 1"
Output: 2
Example 2:

Input: s = " 2-1 + 2 "
Output: 3
Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 

Constraints:

1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer.

*/

#include <cctype>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        //credit to d40a and opedashila
        //TC O(s.size()), SC (n) where n is the number of digits
        stack<int> op({1});
        int total = 0, num = 0, isPositive = 1;
        for(char c:s){
            if(isdigit(c)){
                //eg. + 23 - (238 - 87)
                num = num*10 + (c - '0');
            }else{
                total += num*isPositive*op.top();
                num = 0;
                if(c == '+')isPositive = 1;
                if(c == '-')isPositive = -1;
                if(c == ')')op.pop();
                if(c == '('){
                    op.push(op.top() * isPositive);
                    isPositive = 1;
                }
            }
        }
        //handle the last digit
        total += num * isPositive * op.top();
        return total;
    }
};