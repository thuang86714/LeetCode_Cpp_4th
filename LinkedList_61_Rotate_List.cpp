#include <cstddef>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //TC O(n), SC O(1)
        if(!head){
            return head;
        }

        int len = 1;
        ListNode *cur = head;
        while(cur->next){
            len++;
            cur = cur->next;
        }

        if(k%len == 0){
            return head;
        }

        k %= len;
        cur->next = head;
        for(int i = 0; i < len - k; i++){
            cur = cur->next;
        }

        ListNode *newHead = cur->next;
        cur->next = NULL;

        return newHead;
    }
};