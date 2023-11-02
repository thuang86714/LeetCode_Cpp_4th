#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //credit to labuladong, https://labuladong.github.io/algo/di-er-zhan-a01c6/yong-dong--63ceb/yi-ge-fang-3b01b/
        //TC O(n), SC O(1), sace optimal ver
        int n = prices.size();
        int memo_i_sell = 0, memo_i_buy = -10001;
        for(int i = 0; i < n; i++){
            memo_i_sell = max(memo_i_sell, memo_i_buy + prices[i]);
            memo_i_buy = max(memo_i_buy, -1*prices[i]);        
        }

        return memo_i_sell;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //credit to labuladong, https://labuladong.github.io/algo/di-er-zhan-a01c6/yong-dong--63ceb/yi-ge-fang-3b01b/
        //TC O(n), SC O(2n)
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2));
        for(int i = 0; i < n; i++){
            if(i == 0){
                memo[i][0] = 0;
                memo[i][1] = -1*prices[i];
                continue;
            }

            memo[i][0] = max(memo[i - 1][0], memo[i - 1][1] + prices[i]);
            memo[i][1] = max(memo[i - 1][1], -1*prices[i]);//here we may omit memo[i - 1][0] because we could only do one trasaction        
        }

        return memo[n - 1][0];
    }
};