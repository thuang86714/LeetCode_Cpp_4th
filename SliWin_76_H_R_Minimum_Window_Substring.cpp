#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        //credit to jacklee20499, TC O(m*n), SC O(1)
        vector<int> map(128, 0);//here we use 128 to take all char in ASCII chart

        for(char &c: t){
            map[c]++;
        }

        int counter = t.size();
        int begin = 0, end = 0, len = 100001, head;
        while(end < s.size()){
            if(map[s[end]] > 0){
                counter--;
            }
            map[s[end]]--;
            end++;

            while(counter == 0){
                if(end - begin < len){
                    len = end - begin;
                    head = begin;
                }

                map[s[begin]]++;
                if(map[s[begin]] > 0){
                    counter++;
                }
                begin++;
            }
        }

        if(len == 100001){
            return "";
        }else{
            return s.substr(head, len);
        }
    }
};