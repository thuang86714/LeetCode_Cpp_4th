/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105

*/
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        //find peak and valley
        //credit to hiepit, TC O(n), SC O(1)
        //check edge case: height.size() <= 2
        if(height.size() <= 2)return 0;

        int n = height.size(), maxLeft = height[0], maxRight = height[n - 1];
        int left = 1, right = n - 2, ans = 0;
        //two ptr
        while(left <= right){
            //find the water level
            if(maxLeft < maxRight){
                if(height[left] > maxLeft){
                    maxLeft = height[left];
                }else{
                    ans += maxLeft - height[left];
                }
                left++;
            }else{
                if(height[right] > maxRight){
                    maxRight = height[right];
                }else{
                    ans += maxRight - height[right];
                }
                right--;
            }
        }
        return ans;
    }
};