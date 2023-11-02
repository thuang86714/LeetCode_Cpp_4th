#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        //credit to jacklee20499, TC O(n), SC O(1)
        int water = 0;
        int n = height.size();
        int l = 0, r = n - 1, left_H = height[l], right_H = height[r];
        while(l < r){
            if(left_H < right_H){
                l++;
                left_H = max(left_H, height[l]);
                water += (left_H - height[l]);
            }else{
                r--;
                right_H = max(right_H, height[r]);
                water += (right_H - height[r]);
            }
        }
        
        return water;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        //credit to jacklee20499, TC O(n^2), SC O(1)-->TLE
        int water = 0;
        int n = height.size();
        for(int i = 1; i < n - 1; i++){
            int l = 0, r = 0;
            //find left bound
            for(int j = i; j >= 0; j--){
                l = max(l, height[j]);
            }

            //find right bound
            for(int j = i; j < n; j++){
                r = max(r, height[j]);
            }

            water += min(l, r) - height[i];

        }
        return water;
    }
};