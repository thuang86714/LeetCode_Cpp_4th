#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //credit to kritika_12, TC O(n), SC O(1)
        vector<vector<int>> res;
        int i = 0;
        while(i < intervals.size() && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }

        
        while(i < intervals.size() && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        //pushing the rest
        while(i < intervals.size()){
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};