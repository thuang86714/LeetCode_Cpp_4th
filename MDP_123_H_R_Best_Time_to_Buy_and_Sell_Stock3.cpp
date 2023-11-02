#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // base case
        int memo_i_1_sell = 0, memo_i_1_buy = INT_MIN;
        int memo_i_2_sell = 0, memo_i_2_buy = INT_MIN;
        for (int price : prices) {
            memo_i_2_sell = max(memo_i_2_sell, memo_i_2_buy + price);
            memo_i_2_buy = max(memo_i_2_buy, memo_i_1_sell - price);
            memo_i_1_sell = max(memo_i_1_sell, memo_i_1_buy + price);
            memo_i_1_buy = max(memo_i_1_buy, -price);
        }
        return memo_i_2_sell;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //credit to labuladon, TC O(n*k), SC O(2n*k)
        int n = prices.size(), times = 2;//k = 2 represent at most we could do 2 transactions
        vector<vector<vector<int>>> memo(n, vector<vector<int>> (times + 1, vector<int> (2)));

        for(int i = 0; i < n; i++){
            for(int j = times; j >= 1; j--){
                if(i == 0){
                    memo[i][j][0] = 0;
                    memo[i][j][1] = -1*prices[i];
                    continue;
                }
                memo[i][j][0] = max(memo[i - 1][j][0], memo[i - 1][j][1] + prices[i]);
                memo[i][j][1] = max(memo[i - 1][j][1], memo[i - 1][j - 1][0] - prices[i]);
            }
        }

        return memo[n - 1][times][0];
    }
};