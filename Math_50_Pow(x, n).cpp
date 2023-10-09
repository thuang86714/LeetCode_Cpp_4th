class Solution {
public:
    double ans = 1;
    double myPow(double x, int n) {
        //recursion
        findPow(x, n);
        return ans;
    }

    void findPow(double x, int n){
        if(n == 0)return;

        if(n%2){
            if(n < 0){
                ans /= x;
            }else{
                ans *= x;
            }
        }

        return findPow(x*x, n/2);
    }
};