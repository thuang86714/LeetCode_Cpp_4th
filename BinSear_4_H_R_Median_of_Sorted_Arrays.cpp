#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //credit to stellari
        int N1 = nums1.size();
        int N2 = nums2.size();
        if(N1 < N2){
            return findMedianSortedArrays(nums2, nums1);// Make sure A2 is the shorter one.
        }

        int low = 0, high = 2*N2;
        while(low <= high){
            int mid2 = (low + high)/2;// Cut 2 
            int mid1 = N1 + N2 - mid2;// Calculate Cut 1 accordingly

            double L1 = (mid1 == 0)? INT_MIN: nums1[(mid1-1)/2];// Get L1, R1, L2, R2 respectively
            double L2 = (mid2 == 0)? INT_MIN: nums2[(mid2-1)/2];
            double R1 = (mid1 == N1*2) ?INT_MAX: nums1[(mid1)/2];
            double R2 = (mid2 == N2*2) ?INT_MAX: nums2[(mid2)/2];

            if(L1 > R2){// A1's lower half is too big; need to move C1 left (C2 right)
                low = mid2 + 1;
            }else if (L2 > R1){// A2's lower half too big; need to move C2 left.
                high = mid2 - 1;
            }else{// Otherwise, that's the right cut.
                return (max(L1,L2) + min(R1, R2))/2.0;
            }
        }
        return -1;
    }
};


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //TC O(m+n), SC O(m+n)
        priority_queue<int> minHeap(nums1.begin(), nums1.end());
        for(int num:nums2){
            minHeap.push(num);
        }

        int n = nums1.size(), m = nums2.size(), mid = (n+ m)/2, prev;
        for(int i = 0; i < mid; i++){
            prev = minHeap.top();
            minHeap.pop();
        }

        if((n+m)%2){
            return minHeap.top();    
        }else{
            return (minHeap.top() + prev)/2.0;
        }
    }
};