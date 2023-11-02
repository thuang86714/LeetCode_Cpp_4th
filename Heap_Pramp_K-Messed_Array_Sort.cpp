/*
Given an array of integers arr where each element is at most k places away from its sorted position, code an efficient function sortKMessedArray that sorts arr. For instance, for an input array of size 10 and k = 2, an element belonging to index 6 in the sorted array will be located at either index 4, 5, 6, 7 or 8 in the input array.

Analyze the time and space complexities of your solution.

Example:

input:  arr = [1, 4, 5, 2, 3, 7, 8, 6, 10, 9], k = 2

output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Constraints:

[time limit] 5000ms

[input] array.integer arr

1 ≤ arr.length ≤ 100
[input] integer k

0 ≤ k ≤ 20
[output] array.integer
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> sortKMessedArray( const vector<int>& arr, int k ) 
{

  // TC (nlogk) SC O(k)
  if(k == 0)return arr;
  
  int n = arr.size();
  vector<int> res;
  priority_queue<int, vector<int>, greater<int>> pq;
  
  for(int i = 0; i <= k; i++){
    pq.push(arr[i]);
  }
  
  int j = k +1;
  for(int i = 0; i < n; i++){
    res.push_back(pq.top());
    pq.pop();
    if(j < n){
      pq.push(arr[j]);
      j++;
    }
  }
  return res;
  
}


int main() {
  return 0;
}