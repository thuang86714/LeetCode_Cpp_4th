#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        //credit to jacklee20499
        //TC O(n^2), SC O(n)
        int ans = 1;
        int n = points.size();

        for(int i = 0; i < n; i++){
            unordered_map<string, int> slopeMap;
            for(int j = i + 1; j < n; j++){
                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];
                int gcd = __gcd(dx, dy);
                string slope = to_string(dx/gcd) + "/" + to_string(dy/gcd);
                slopeMap[slope]++;

                ans = max(ans, slopeMap[slope]+1);//+1 for the points[i] itself
            }
        }

        return ans;
    }
};