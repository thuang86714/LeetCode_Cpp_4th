#include <unordered_set>
using namespace std;

class Solution {
public:
    int NewNum(int n){
        int New = 0;
        while(n > 0){
            int tail = n%10;
            New += tail*tail;
            n /= 10;
        }
        return New;
    }
    bool isHappy(int n) {
        unordered_set<int> visited;
        while(n != 1 && !visited.count(n)){
            visited.insert(n);
            n = NewNum(n);
        }
        return n == 1;
    }
};