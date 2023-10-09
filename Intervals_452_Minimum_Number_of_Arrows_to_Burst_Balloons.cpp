#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int arrow = 1, tail = points[0][1];
        for(int i = 1; i < points.size(); i++){
            if(tail < points[i][0]){
                tail = points[i][1];
                arrow++;
            }
            tail = min(tail, points[i][1]);
        }
        return arrow;
    }
};