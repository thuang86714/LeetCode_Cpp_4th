class Solution {
public:
    int trailingZeroes(int n) {
        //count the number of 2*5
        int sum = 0, five = 5;
        while(n/five >= 1){
            sum += n/five;
            five *= 5;
        }

        return sum;
    }
};