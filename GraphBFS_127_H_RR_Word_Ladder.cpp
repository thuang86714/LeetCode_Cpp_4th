#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //credit to jacklee20499, for making the function addNextWord
        //TC O(m*n), SC O(m)
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> toVisit;
        toVisit.push(beginWord);
        int ladder = 2;//given beginWord != endWord
        addNextWord(beginWord, dict, toVisit);
        while(!toVisit.empty()){
            int size = toVisit.size();
            for(int i = 0; i < size; i++){
                string word = toVisit.front();
                toVisit.pop();

                if(word == endWord){
                    return ladder;
                }
                addNextWord(word, dict, toVisit);
            }
            ladder++;
        }
        return 0;
    }
private:
    void addNextWord(string &word, unordered_set<string> &dict, queue<string> &toVisit){
        dict.erase(word);
        for(int i = 0; i < word.size(); i++){
            char temp = word[i];
            for(int j = 0; j < 26; j++){
                word[i] = 'a' + j;
                if(dict.find(word) != dict.end()){
                    toVisit.push(word);
                    dict.erase(word);
                }
            }
            word[i] = temp;
        }
    }
};


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict{wordList.begin(), wordList.end()};

        int ladder = 1;
        queue<string> toVisit;
        toVisit.push(beginWord);
        if(dict.count(beginWord)){
            dict.erase(beginWord);
        }

        while(!toVisit.empty()){
            int size = toVisit.size();
            for(int i = 0; i < size; i++){
                string word = toVisit.front();
                toVisit.pop();

                if(word == endWord){
                    return ladder;
                }
                for(int j = 0; j < word.size(); j++){
                    char temp = word[j];
                    for(int k = 0; k < 26; k++){
                        word[j] = 'a' + k;
                        if(dict.count(word)){
                            toVisit.push(word);
                            dict.erase(word);
                        }
                    }
                    word[j] = temp;
                }
            }
            ladder++;
        }
        return 0;
    }
};