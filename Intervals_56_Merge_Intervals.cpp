#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //TC O(nlogn), SC O(1)
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        int i = 0;
        while(i < intervals.size()){
            vector<int> temp {intervals[i][0]};
            int tail = intervals[i][1];
            while(i < intervals.size() && tail >= intervals[i][0]){
                tail = max(tail, intervals[i][1]);
                i++;
            }
            temp.push_back(tail);
            res.push_back(temp);
        }
        return res;
    }
};