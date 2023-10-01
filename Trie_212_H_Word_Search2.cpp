/*
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Example 1:
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]

Example 2:
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
 

Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.
*/
#include <vector>
#include <unordered_set>
using namespace std;
//credit to rabeeh
struct TrieNode{
    bool isEnd;
    vector<TrieNode*> children;
    TrieNode(){
        isEnd = false;
        children = vector<TrieNode*>(26, NULL);
    }
};

class Trie{
public:
    TrieNode* getRoot(){
        return root;
    }

    Trie(vector<string>& words){
        root = new TrieNode();
        for(int i = 0; i < words.size(); i++){
            addWord(words[i]);
        }
    }

    void addWord(const string& word){
        TrieNode *cur = root;
        for(int i = 0; i < word.size(); i++){
            int index = word[i] - 'a';
            if(cur->children[index] == NULL){
                cur->children[index] = new TrieNode();
            }
            cur = cur->children[index];
        } 
        cur->isEnd = true;
    }
private:
    TrieNode *root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *trie = new Trie(words);
        TrieNode *root = trie->getRoot();
        unordered_set<string> result_set;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                helper(board, i, j, root, "", result_set);
            }
        }

        vector<string> result;
        for(auto it:result_set){
            result.push_back(it);
        }
        delete trie;//as a good habit
        return result;
    }
private:
    void helper(vector<vector<char>>& board, int i, int j, TrieNode* root, string word, unordered_set<string>& result){
        //base case
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#')return;
        if(root->children[board[i][j] - 'a'] != NULL){
            word = word + board[i][j];
            root = root->children[board[i][j] - 'a'];
            if(root->isEnd)result.insert(word);
            char temp = board[i][j];
            //avoid redundant traversing
            board[i][j] = '#';
            helper(board, i + 1, j, root, word, result);
            helper(board, i - 1, j, root, word, result);
            helper(board, i, j + 1, root, word, result);
            helper(board, i, j - 1, root, word, result);
            board[i][j] = temp;
        }
    }
};