#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //credit to jianchao-li
        //moore voting algorithm, TC O(n), SC O(1)
        int counter = 0, majority;
        for(int &n:nums){
            if(!counter){
                majority = n;
            }
            if(n == majority){
                counter++;
            }else{
                counter--;
            }
        }

        return majority;
    }
};