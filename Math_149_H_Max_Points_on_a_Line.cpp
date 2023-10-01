/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

 

Example 1:
Input: points = [[1,1],[2,2],[3,3]]
Output: 3
Example 2:
Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
 

Constraints:

1 <= points.length <= 300
points[i].length == 2
-104 <= xi, yi <= 104
All the points are unique.
*/

#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        //credit to jianchao-li, TC O(n^2), SC O(1)
        int n = points.size(), ans = 0;
        for(int i = 0; i < n; i++){
            unordered_map<string, int> map;
            int dup = 1;
            for(int j = i + 1; j < n; j++){
                if(points[j][0] == points[i][0] && points[j][1] == points[i][1]){
                    dup++;//to handle the case of duplicate points simply by adding the number of duplicates to the result.
                }else{
                    int dx = points[j][0] - points[i][0], dy = points[j][1] - points[i][1], g = __gcd(dx, dy);
                    map[to_string(dx/g) + '_' + to_string(dy/g)]++;
                }
            }
            ans = max(ans, dup);
            for(auto it:map){
                ans = max(ans, it.second + dup);
            }
        }
        return ans;

    }
};