#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //credit to labuladong TC O(n), SC O(1)
        int n = prices.size();
        int memo_i_sell = 0, memo_i_buy = -50001;
        for(int i = 0; i < n; i++){
            int yesterday_sell = memo_i_sell;
            memo_i_sell = max(memo_i_sell, memo_i_buy + prices[i]);
            memo_i_buy = max(memo_i_buy, yesterday_sell - prices[i] - fee);
        }

        return memo_i_sell;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //credit to labuladong TC O(n), SC O(2n)
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2));
        for(int i = 0; i < n; i++){
            if(i == 0){
                memo[i][0] = 0;
                memo[i][1] = -1*(prices[i] + fee);
                continue;
            }
            memo[i][0] = max(memo[i - 1][0], memo[i - 1][1] + prices[i]);
            memo[i][1] = max(memo[i - 1][1], memo[i - 1][0] - prices[i] - fee);
        }

        return memo[n - 1][0];
    }
};