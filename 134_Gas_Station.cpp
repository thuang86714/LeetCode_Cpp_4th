#include <vector>
using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //if gas_sum < cost_sum, then return -1
        int gas_sum = 0, cost_sum = 0, diff = 0, index = 0;
        for(int i = 0; i < gas.size(); i++){
            gas_sum += gas[i];
            cost_sum += cost[i];

            diff += gas[i] - cost[i];
            if(diff < 0){
                index = i + 1;
                diff = 0;
            }
        }

        if(gas_sum < cost_sum){
            return -1;
        }else{
            return index;
        }
    }
};