class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        //credit to Ajna
        //Well, yes, if we notice that we are basically proceeding shaving the least significant bit as long as l and r are different; 
        int count = 0;
        while(left && left != right){
            left >>= 1;
            right >>= 1;
            count++;
        }
        return left <<count;
    }
};