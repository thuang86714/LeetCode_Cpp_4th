#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int len_count = 0;
        vector<string> res, tempVec;
        for(string word:words){
            if(len_count + tempVec.size() + word.size() > maxWidth){
                int total_space = maxWidth - len_count;
                int gaps = tempVec.size() -1;
                string temp = "";
                if(gaps == 0){
                    temp += tempVec[0] + string(total_space, ' ');
                }else{
                    int standard_space = total_space/gaps;
                    int extra_space = total_space%gaps;
                    for(int i = 0; i < tempVec.size(); i++){
                        temp += tempVec[i];
                        if(i < gaps){
                            temp += string(standard_space, ' ');
                            if(i < extra_space){
                                temp += string(1, ' ');
                            }
                        }
                    }
                }
                res.push_back(temp);
                tempVec.clear();
                len_count = 0;
            }
            tempVec.push_back(word);
            len_count += word.size();
            
        }
        //handle the last line
        int trailing_space = maxWidth - len_count - tempVec.size() + 1;
        int gaps = tempVec.size() -1;
        string temp = "";
        for(int i = 0; i < tempVec.size(); i++){
            temp += tempVec[i];
            if(i < gaps){
                temp += string(1, ' ');
            }
        }
        temp += string(trailing_space,' ');
        res.push_back(temp);
        return res;
    }
};