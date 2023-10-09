#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(!nums.size())return res;
        int head = nums[0], tail = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == tail+1){
                tail++;
                continue;
            }
            if(head == tail){
                res.push_back(to_string(head));
            }else{
                string temp = to_string(head) + "->" + to_string(tail);
                res.push_back(temp);
            }
            
            head = nums[i];
            tail = nums[i];
        }
        if(head == tail)res.push_back(to_string(head));
        else{
            string temp = to_string(head) + "->" + to_string(tail);
            res.push_back(temp);
        }
        return res;
    }
};