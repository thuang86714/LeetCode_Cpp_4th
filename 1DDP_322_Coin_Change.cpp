#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1, amount+1);
        memo[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int c: coins){
                if(i >= c){
                    memo[i] = min(memo[i], memo[i - c] + 1);
                }
            }
        }

        if(memo.back() == amount+1){
            return -1;
        }
        return memo.back();
    }
};