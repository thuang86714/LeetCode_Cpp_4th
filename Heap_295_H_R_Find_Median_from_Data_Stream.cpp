#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class MedianFinder {
public:
//TC O(nlogn), SC O(n)
    vector<int> v;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        v.push_back(num);
    }
    
    double findMedian() {
        sort(v.begin(), v.end());
        int len = v.size();
        if(len%2 == 0){
            return double((v[len/2-1 ] + v[len/2])/2.0);
        }else{
            return double(v[(len-1)/2]);
        }
    }
};


class MedianFinder {
public:
    //credit to jacklee20499, TC O(logN), SC O(N)
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        int size = minHeap.size() + maxHeap.size();
        if(size%2){
            return (double)maxHeap.top();
        }else{
            return double(maxHeap.top() + minHeap.top()) /2.0;
        }
    }
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;//larger half
    priority_queue<int> maxHeap;//smaller half
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */