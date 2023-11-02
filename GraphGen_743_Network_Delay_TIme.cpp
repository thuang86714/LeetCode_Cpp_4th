#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //credit to jacklee20499, Time complexity: O(nlogn), Space complexity: O(n)
        vector<vector<pair<int, int>>> g(n+1);
        for(auto &t:times){
            g[t[0]].push_back({t[1], t[2]});
        }
        
        vector<int> distance(n+1, INT_MAX-200);
        distance[0] = 0;
        distance[k] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>> > pq;
        pq.push({0, k});
        
        while(!pq.empty()){
            auto cost = pq.top().first;
            auto cur = pq.top().second;
            pq.pop();
            
            for(auto &[nxt, diff]: g[cur]){
                if( distance[nxt] >  cost + diff ){
                    distance[nxt] = cost + diff;
                    pq.push({distance[nxt], nxt});
                }
            }
        }
        
        for(int i=0; i<n+1; i++){
            if(distance[i] == (INT_MAX-200)) return -1;
        }
        
        return *max_element(distance.begin(), distance.end());
    }
};