#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        //credit to hiepit and jacklee20499, TC O(n), SC O(1)
        int n = height.size();
        int left = 0, right = n - 1;
        int LeftMax = height[left], RightMax = height[right];
        int water = 0;
        //two ptr
        while(left < right){
            if(LeftMax < RightMax){
                left++;
                LeftMax = max(LeftMax, height[left]);
                water += (LeftMax - height[left]);
            }else{
                right--;
                RightMax = max(RightMax, height[right]);
                water += (RightMax - height[right]);
            }
        }
        return water;
    }
};

class Solution{
public:
    int trap(vector<int>& height) {
        //TC O(n), SC O(n)
        int n = height.size();
        vector<int> LeftMax(n), RightMax(n);

        //find the left bound
        for(int i = 1; i < n; i++){
            LeftMax[i] = max(height[i - 1], LeftMax[i - 1]);
        }

        //find the right bound
        for(int i = n - 2; i >= 0; i--){
            RightMax[i] = max(height[i + 1], RightMax[i + 1]);
        }

        int water = 0;
        for(int i = 0; i < n; i++){
            int WaterLevel = min(LeftMax[i], RightMax[i]);
            if(height[i] <= WaterLevel){
                water += WaterLevel - height[i];
            }
        }
        return water;
    }
};

class Solution{
public:
    int trap(vector<int>& height) {
        //TC O(n^2), SC O(1)
        int n = height.size();
        int water = 0;
        for(int i = 1; i < n - 1; i++){
            int l = 0, r = 0;
            for(int j = i; j >= 0; j--){
                l = max(l, height[j]);
            }
            for(int j = i; j < n; j++){
                r = max(r, height[j]);
            }

            water = min(l, r) - height[i];
        }
        return water;
    }
};