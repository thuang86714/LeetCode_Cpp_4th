#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //credit to labuladong TC O(n), SC O(1)
        int n = prices.size();
        int memo_i_sell = 0, memo_i_buy = -1001, memo_last_sell_day = 0;
        for(int i = 0; i < n; i++){
            int last_sell_day = memo_i_sell;
            memo_i_sell = max(memo_i_sell, memo_i_buy + prices[i]);
            memo_i_buy = max(memo_i_buy, memo_last_sell_day - prices[i]);
            memo_last_sell_day = last_sell_day;
        }

        return memo_i_sell;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //credit to labuladong TC O(n), SC O(2n)
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int> (2));
        for(int i = 0; i < n; i++){
            if(i == 0){
                memo[i][0] = 0;
                memo[i][1] = -1*prices[i];
                continue;
            }
            if(i == 1){
                memo[i][0] = max(memo[i - 1][0], memo[i - 1][1] + prices[i]);
                memo[i][1] = max(memo[i - 1][1], memo[i - 1][0] - prices[i]);
                continue;
            }

            memo[i][0] = max(memo[i - 1][0], memo[i - 1][1] + prices[i]);
            memo[i][1] = max(memo[i - 1][1], memo[i - 2][0] - prices[i]);
        }

        return memo[n - 1][0];
    }
};