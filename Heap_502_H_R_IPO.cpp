#include <unordered_set>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //credit to jacklee20499, TC O(nlogn + k*logn)
        vector<pair<int, int>> projects;
        int n = profits.size();
        for(int i = 0; i < n; i++){
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());//nlogn
        priority_queue<int> maxHeap;
        int idx = 0;
        for(int i = 0 ; i < k; i++){//k*logn
            while(idx < n && projects[idx].first <= w){
                maxHeap.push(projects[idx].second);
                idx++;
            }

            if(!maxHeap.empty()){
                w += maxHeap.top();
                maxHeap.pop();
            }else{
                break;
            }
        }
        return w;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //credit to jacklee20499, TC O(k*nlogn), SC O(n)
        map<int, vector<int>> projects;
        int n = profits.size();
        for(int i = 0; i < n; i++){
            projects[capital[i]].push_back(profits[i]);
        }

        priority_queue<int> maxHeap;

        for(int i = 0; i < min(k,n); i++){

            for(auto &p:projects){
                if(p.first <= w){
                    for(int earning:p.second){
                        maxHeap.push(earning);
                    }
                    projects.erase(p.first);
                }else{
                    break;//map is ordered
                }
            }

            if(maxHeap.empty()){
                break;
            }
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        //credit to jacklee20499, TC O(min(n, k)*n), SC O(n)-->Brute Force/TLE
        int n = profits.size();
        unordered_set<int> visited;
        for(int i = 0; i < min(k, n); i++){
            int curProfit = 0;
            int idx = -1;
            for(int j = 0; j < n; j++){
                if(capital[j] <= w){
                    if(!visited.count(j) && curProfit < profits[j]){
                        idx = j;
                        curProfit = profits[j];
                    }
                }
            }
            w += curProfit;
            visited.insert(idx);
        }

        return w;
    }
};


