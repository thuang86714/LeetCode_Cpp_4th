#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        //credit to TITAN, TC O(n), SC O(1)
        int n = ratings.size();
        int candy = n, idx = 1;
        while(idx < n){
            while(ratings[idx] == ratings[idx - 1]){
                idx++;
            }

            int peak = 0;
            while(ratings[idx] > ratings[idx - 1]){
                peak++;
                candy += peak;
                idx++;
                if(idx == n){
                    return candy;
                }
            }

            int valley = 0;
            while(idx < n && ratings[idx] < ratings[idx - 1]){
                valley++;
                candy += valley;
                idx++;
            }
            candy -= min(peak, valley);
        }
        return candy;
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        //credit to neetcode, TC O(n), SC O(n)
        int n = ratings.size();
        vector<int> candies(n, 1);

        for(int i = 1; i < n; i++){
            if(ratings[i - 1] < ratings[i]){
                candies[i] = candies[i - 1] + 1;
            }
        }

        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};