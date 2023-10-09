#include <cmath>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        //binary search
        int l = 0, r = x;
        while(l < x){
            int mid = (l + r)/2;
            if(pow(mid,2) <= x && pow(mid+1, 2) > x)return mid;
            else if(x < pow(mid, 2))r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};