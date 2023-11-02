#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        //credit to vanAmsen, TC O(n), where n is number of words in words. SC O(n*m), where m is the average length of words
        vector<string> res, cur_words;
        int cur_len = 0;

        for(string &s:words){
            if(cur_len + s.size() + cur_words.size() > maxWidth){
                int total_spaces = maxWidth - cur_len;
                int gaps = cur_words.size() - 1;
                if(gaps == 0){
                    res.push_back(cur_words[0] + string(total_spaces, ' '));
                }else{
                    int space_per_gap = total_spaces/gaps;
                    int extra_spaces = total_spaces%gaps;
                    string line = "";
                    for(int i = 0; i < cur_words.size(); i++){
                        line += cur_words[i];
                        if(i < gaps){
                            line += string(space_per_gap, ' ');
                            if(i < extra_spaces){
                                line += ' ';
                            }
                        }
                    }
                    res.push_back(line);
                }
                //reset
                cur_words.clear();
                cur_len = 0;
            }
            cur_words.push_back(s);
            cur_len += s.size();
        }

        string last_line = "";
        for(string word: cur_words){
            if(!last_line.empty()){
                last_line += ' ';
            }
            last_line += word;
        }
        last_line += string(maxWidth - last_line.size(), ' ');
        res.push_back(last_line);

        return res;
    }
};