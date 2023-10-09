#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0, l = 0, r = height.size()-1;
        while(l < r){
            int h = min(height[l], height[r]);
            int w = r - l;
            water = max(water, w*h);
            while(l < r && h >= height[l])l++;
            while(l < r && h >= height[r])r--;
        }
        return water;
    }
};
