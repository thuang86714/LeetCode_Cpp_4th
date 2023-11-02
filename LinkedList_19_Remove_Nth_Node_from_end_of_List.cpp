struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *left = dummy, *right = dummy;
        for(int i = 0; i < n; i++){
            left = left->next;
        }

        while(left->next){
            right = right->next;
            left = left->next;
        }
        ListNode *to_be_deleted = right->next;
        right->next = right->next->next;
        delete to_be_deleted;
        return dummy->next;
    }
};