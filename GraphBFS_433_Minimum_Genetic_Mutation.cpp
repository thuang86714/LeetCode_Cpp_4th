#include <string>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<char> gene{'A', 'C', 'G', 'T'};
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        //BFS
        unordered_set<string> dict(bank.begin(), bank.end());

        queue<string> toVisit;
        toVisit.push(startGene);
        dict.erase(startGene);
        int mutation = 0;

        while(!toVisit.empty()){
            int len = toVisit.size();
            for(int i = 0; i < len; i++){
                string cur = toVisit.front();
                toVisit.pop();

                if(cur == endGene){
                    return mutation;
                }

                findMutation(cur, dict, toVisit);
            }
            mutation++;
        }

        return -1;
    }
private:
    void findMutation(string cur, unordered_set<string> &dict, queue<string> &toVisit){
        for(int j = 0; j < cur.size(); j++){
            char temp = cur[j];
            for(int k = 0; k < gene.size(); k++){
                cur[j] = gene[k];
                if(dict.count(cur)){
                    toVisit.push(cur);
                    dict.erase(cur);
                }
            }
            cur[j] = temp;
        }
    }
};