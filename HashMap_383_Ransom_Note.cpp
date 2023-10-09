#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //credit to Akshatkamboj37 && mosiur404
        //TC O(n+m), SC O(1)
        int freq[26] = {0};
        int charAscii = 97;
        for(int i = 0; i < magazine.size(); i++){
            freq[magazine[i] - charAscii]++;
        }

        for(int i = 0; i < ransomNote.size(); i++){
            if(--freq[ransomNote[i] - charAscii] < 0)return false;
        }

        return true;
    }
};


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //<char, count>
        unordered_map<char, int> map;
        //TC O(n + m), SC O(n + m)
        for(char c: magazine){
            map[c]++;
        }

        for(char c: ransomNote){
            map[c]--;
        }

        for(auto it:map){
            if(it.second < 0)return false; 
        }

        return true;
    }
};
