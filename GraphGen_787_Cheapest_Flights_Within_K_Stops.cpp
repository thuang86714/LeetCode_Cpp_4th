#include <vector>
#include <queue>
#include <cmath>
using namespace std;


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        /*credit to jacklee20499 
        Time complexity: O(n^2 * k) => 10e6
        Space complexity: O(n*k)
        把k當成搜尋的範圍，因為contraints 說 k<n<100，這樣會大大減少搜尋的範圍*/
        buildGraph(n, flights);
        vector<int> dist(n+1, INT_MAX/2);
        dist[src] = 0;
        //{stop, city, cost}
        queue<vector<int>> toVisit;
        toVisit.push({0, src, 0});
        while(!toVisit.empty()){
            int curCost = toVisit.front()[2];
            int curCity = toVisit.front()[1];
            int curStops = toVisit.front()[0];
            toVisit.pop();

            if(curStops == k + 1){
                continue;//have stoped more than allowed
            }

            for(auto &adj:graph[curCity]){
                int nextCity = adj.first;
                int nextCost = adj.second;
                if(dist[nextCity] > curCost + nextCost && curStops <= k){
                    dist[nextCity] = curCost + nextCost;
                    toVisit.push({curStops + 1, nextCity, curCost + nextCost});
                }
            }
        }

        if(dist[dst] == INT_MAX/2){
            return -1;
        }else{
            return dist[dst];
        }
    }
private:
    vector<vector<pair<int,int>>> graph;
    void buildGraph(int n, vector<vector<int>> &flights){
        graph.resize(n + 1);//1 <= n <= 100
        for(auto &flight:flights){
            int from = flight[0], to = flight[1], price = flight[2];
            graph[from].push_back({to, price});
        }
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        /*Time complexity: O( E+V×K×log(V×K) ) => 
        Space complexity: O( V×K+E )*/
        
        buildGraph(n, flights);
        vector<vector<int>> cost(n+1, vector<int> (k+2, INT_MAX/2));

        //{cost, city, stop}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        minHeap.push({0, src, 0});
        while(!minHeap.empty()){
            int curCost = minHeap.top()[0];
            int curCity = minHeap.top()[1];
            int curStops = minHeap.top()[2];
            minHeap.pop();

            if(curCity == dst){
                return curCost;
            }

            if(curStops == k + 1){
                continue;//have stoped more than allowed
            }

            if(cost[curCity][curStops] < INT_MAX/2){
                continue;
            }

            cost[curCity][curStops] = curCost;
            for(auto &adj:graph[curCity]){
                int nextCity = adj.first;
                int nextCost = adj.second;
                if(cost[nextCity][curStops+1] == INT_MAX/2){
                    minHeap.push({curCost + nextCost, nextCity, curStops+1});
                }
            }
        }

        return -1;
    }
private:
    vector<vector<pair<int,int>>> graph;
    void buildGraph(int n, vector<vector<int>> &flights){
        graph.resize(n + 1);//1 <= n <= 100
        for(auto &flight:flights){
            int from = flight[0], to = flight[1], price = flight[2];
            graph[from].push_back({to, price});
        }
    }
};