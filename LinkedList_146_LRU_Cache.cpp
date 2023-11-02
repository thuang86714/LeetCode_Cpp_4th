#include <cstddef>
#include <unordered_map>
using namespace std;


struct Node{
        Node *prev;
        Node *next;
        int val;
        int key;
        Node(int key, int val){
            this->prev = NULL;
            this->next = NULL;
            this->val = val;
            this->key = key;
        }
};

class LRUCache {
public:
    LRUCache(int capacity) {
        this->cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(map.find(key) == map.end()){
            return -1;
        }
        Node *cur = map[key];
        remove(cur);
        insert(cur);
        return cur->val;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            remove(map[key]);
        }

        if(map.size() == cap){
            remove(tail->prev);
        }

        Node *NewNode = new Node(key, value);
        insert(NewNode);
    }
private:
    Node *head = new Node(0, 0);
    Node *tail = new Node(0, 0);
    unordered_map<int, Node*> map;
    int cap;

    void remove(Node* node){
        Node *before = node->prev;
        Node *after = node->next;
        before->next = after;
        after->prev = before;
        map.erase(node->key);
    }

    void insert(Node *node){
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
        map[node->key] = node;
    }
};
