#include <vector>
using namespace std;


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> sell(k + 1), buy(k + 1);

        for(int i = 0; i < n; i++){
            for(int j = k; j >= 1; j--){
                if(i == 0){
                    sell[j] = 0;
                    buy[j] = -1*prices[i];
                    continue;
                }
                sell[j] = max(sell[j], buy[j] + prices[i]);
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
            }
        }

        return sell[k];
    }
};

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //credit to labuladong, TC O(n*k), SC O(2n*k)
        int n = prices.size();
        /*
        if (n <= 0) {
        return 0;
        }
        if (max_k > n / 2) {
            // 复用之前交易次数 k 没有限制的情况
            return maxProfit_k_inf(prices);
        }
        */
        vector<vector<vector<int>>> memo(n, vector<vector<int>> (k + 1, vector<int>(2)));
        
        for(int i = 0; i < n; i++){
            for(int j = k; j >= 1; j--){
                if(i == 0){
                    memo[i][j][0] = 0;
                    memo[i][j][1] = -1*prices[i];
                    continue;
                }

                memo[i][j][0] = max(memo[i - 1][j][0], memo[i - 1][j][1] + prices[i]);
                memo[i][j][1] = max(memo[i - 1][j][1], memo[i - 1][j - 1][0] - prices[i]);
            }
        }

        return memo[n - 1][k][0];
    }
};