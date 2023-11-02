#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n;
        int idx = 1;
        while(idx < n){
            //plateau
            while(idx < n && ratings[idx] == ratings[idx - 1]){
                idx++;
            }

            //rising slope
            int peak = 0;
            while(idx < n && ratings[idx] > ratings[idx - 1]){
                peak++;
                candy += peak;
                idx++;
                if(idx == n)return candy;
            }

            //descending slope
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
        int n = ratings.size();
        vector<int> candy(n, 1);
        for(int i = 1; i < n; i++){
            if(ratings[i - 1] < ratings[i]){
                candy[i] = candy[i - 1] + 1;
            }
        }

        for(int i = n - 2; i >= 0; i--){
            if(ratings[i + 1] < ratings[i]){
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
        }
        return accumulate(candy.begin(), candy.end(), 0);
    }
};