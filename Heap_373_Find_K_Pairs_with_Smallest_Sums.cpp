#include <queue>
#include <vector>
using namespace std;

#define ppii pair<int, pair<int, int>>
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<ppii> pq;

        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                int sum = nums1[i] + nums2[j];
                if(pq.size() < k){
                    pq.push({sum, {nums1[i], nums2[j]}});
                }else if(pq.top().first > sum){
                    pq.pop();
                    pq.push({sum, {nums1[i], nums2[j]}});
                }else break;
            }
        }

        vector<vector<int>> res;
        while(!pq.empty()){
            res.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }

        return res;
    }
};