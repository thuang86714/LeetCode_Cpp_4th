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
    ListNode* partition(ListNode* head, int x) {
        ListNode *greater = new ListNode();
        ListNode *greater_head = greater;
        ListNode *smaller = new ListNode();
        ListNode *smaller_head = smaller;

        while(head){
            if(head->val >= x){
                greater->next = head;
                greater = greater->next;
            }else{
                smaller->next = head;
                smaller = smaller->next;
            }
            head = head->next;
        }
        smaller->next = greater_head->next;
        greater->next = NULL;

        return smaller_head->next;

    }
};