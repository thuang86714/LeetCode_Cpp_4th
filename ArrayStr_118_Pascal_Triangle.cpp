#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //TC O(numRows^2), SC O(numRows)
        vector<vector<int>> res;
        for(int i = 0; i < numRows; i++){
            vector<int> tempVec(1, 1);
            if(i == 0){
                res.push_back(tempVec);
                continue;
            }
            vector<int> lastRow = res.back();
            
            for(int j = 1; j < i; j++){
                int sum = lastRow[j - 1] + lastRow[j];
                tempVec.push_back(sum);
            }
            tempVec.push_back(1);
            res.push_back(tempVec);

        }
        return res;
    }
};