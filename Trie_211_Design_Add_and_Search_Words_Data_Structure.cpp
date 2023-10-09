#include <vector>
#include <string>
using namespace std;

struct TrieNode{
    bool isEnd = false;
    vector<TrieNode*> next;
    TrieNode(): next(26, nullptr){};
};
class WordDictionary {
public:
    /*
    Time Complexity :- BigO(M) for well defined words, But in worse case BigO(M.26^N)
    Space Complexity :- BigO(1) for well defined words, But for worst case BigO(M)
    */
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        TrieNode *node = root;
        for(char c: word){
            int num = c - 'a';
            if(!node->next[num]){
                node->next[num] = new TrieNode();
            }
            node = node->next[num];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return ExistorNot(word, root, 0);
    }
private:
    TrieNode *root = new TrieNode();
    bool ExistorNot(string word, TrieNode *node, int idx){
        if(idx >= word.size())return node->isEnd;

        if(word[idx] != '.'){
            node = node->next[word[idx] - 'a'];
            return node && ExistorNot(word, node, idx+1);
        }

        if(word[idx] == '.'){
            for(int i = 0; i < 26; i++){
                if(node->next[i] && ExistorNot(word, node->next[i], idx+1))return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */