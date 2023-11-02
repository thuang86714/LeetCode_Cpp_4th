#include <queue>
using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return root;
        }

        queue<Node*> toVisit;
        toVisit.push(root);

        while(!toVisit.empty()){
            int size = toVisit.size();
            Node *R = NULL;
            for(int i = 0; i < size; i++){
                Node *node = toVisit.front();
                toVisit.pop();
                node->next = R;
                if(node->right){
                    toVisit.push(node->right);
                }
                if(node->left){
                    toVisit.push(node->left);
                }
                R = node;
            }
        }

        return root;
    }
};