#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tempVec;
        for(int n:nums){
            if(tempVec.empty() || tempVec.back() < n){
                tempVec.push_back(n);
            }else{
                *lower_bound(tempVec.begin(), tempVec.end(), n) = n;
            }
        }
        return tempVec.size();
    }
};