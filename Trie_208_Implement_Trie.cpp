#include <string>
#include <unordered_map>
using namespace std;

class Trie {
public:
    Trie() {
        
    }
    
    void insert(string word) {
        Trie *node = this;
        for(char c:word){
            if(!node->next[c]){
                node->next[c] = new Trie();
            }
            node = node->next[c];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie *node = this;
        for(char c:word){
            if(!node->next[c])return false;
            node = node->next[c];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie *node = this;
        for(char c:prefix){
            if(!node->next[c])return false;
            node = node->next[c];
        }
        return true;
    }

private:
    bool isEnd = false;
    unordered_map<char, Trie*> next;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */