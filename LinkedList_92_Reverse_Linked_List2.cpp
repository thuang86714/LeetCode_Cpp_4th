#include <vector>
#include <algorithm>
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode();
        ListNode *prev = dummy;
        dummy->next = head;

        for(int i = 1; i < left; i++){
            prev = prev->next;
        }

        ListNode *pivot = prev->next;
        for(int i = left; i < right; i++){
            ListNode *node = pivot->next;
            pivot->next = node->next;
            node->next = prev->next;
            prev->next = node;
        }

        return dummy->next;
    }
};


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode();
        ListNode *prev, *cur = dummy;
        dummy->next = head;
        vector<ListNode*> tempVec;
        for(int i = 0; i < left; i++){
            prev = cur;
            cur = cur->next;
        }

        for(int i = left; i <= right; i++){
            tempVec.push_back(cur);
            cur = cur->next;
        }

        reverse(tempVec.begin(), tempVec.end());
        for(auto &node:tempVec){
            prev->next = node;
            prev = prev->next;
        }
        prev->next = cur;

        return dummy->next;
    }
};