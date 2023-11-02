#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int l = 0, r = citations.size() -1, len = citations.size();
        while(l <= r){
            int mid = (l + r)/2;
            if(citations[mid] < len - mid){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return len - l;
    }
};