#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //credit to amanrathore48, TC O(m+n), SC O(1)
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(j >= 0){
            if(i >= 0 && nums1[i] > nums2[j]){
                nums1[k] = nums1[i];
                i--;
            }else{
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tempVec;
        for(int i = 0; i < m; i++){
            tempVec.push_back(nums1[i]);
        }

        int ptr_temp = 0, ptr_2 = 0, ptr_1 = 0;
        while(ptr_temp < m && ptr_2 < n){
            if(tempVec[ptr_temp] > nums2[ptr_2]){
                nums1[ptr_1] = nums2[ptr_2];
                ptr_2++;
            }else{
                nums1[ptr_1] = tempVec[ptr_temp];
                ptr_temp++;
            }
            ptr_1++;
        }

        while(ptr_temp < m){
            nums1[ptr_1] = tempVec[ptr_temp];
            ptr_temp++;
            ptr_1++;
        }

        while(ptr_2 < n){
            nums1[ptr_1] = nums2[ptr_2];
            ptr_2++;
            ptr_1++;
        }
    }
};