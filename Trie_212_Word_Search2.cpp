#include <vector>
#include <string>
using namespace std;

class Solution {
public:
//credit to yavinci, tp7309, and zean_7
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        TrieNode *root = buildTrie(words);
        vector<string> result;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                findWordinTrie(board, i, j, root, result);
            }
        }
        ClearTrie(root);
        return result;
    }
private:
    struct TrieNode {
        TrieNode *children[26];
        string word;

        TrieNode() : word("") {
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };

    /** Inserts a word into the trie. */
    TrieNode *buildTrie(vector<string> &words) {
        TrieNode *root = new TrieNode();
        for (int j = 0; j < words.size(); j++) {
            string w = words[j];
            TrieNode *curr = root;
            for (int i = 0; i < w.size(); i++) {
                char c = w[i] - 'a';
                if (curr->children[c] == nullptr) {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
            }
            curr->word = w;
        }
        return root;
    }

    void ClearTrie(TrieNode *root){
        for(int i = 0; i < 26; i++){
            if(root->children[i]){
                ClearTrie(root->children[i]);
            }
        }
        delete(root);
    }

    vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void findWordinTrie(vector<vector<char>> &board, int x, int y, TrieNode *cur, vector<string> &result) {
        char c = board[x][y];
        if (c == '#' || !cur->children[c - 'a']) return;
        cur = cur->children[c - 'a'];
        if (cur->word.size() > 0) {
            result.push_back(cur->word);
            cur->word = "";
        }

        board[x][y] = '#';
        for(int i = 0; i < dir.size(); i++){
            int next_x = x + dir[i].first;
            int next_y = y + dir[i].second;
            if(next_x < 0 || next_x >= board.size() || next_y < 0 || next_y >= board[0].size()){
                continue;
            }
            findWordinTrie(board, next_x, next_y, cur, result);
        }
        board[x][y] = c;
    }
};