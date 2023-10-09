struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        int carry = 0;
        while(l1 || l2){
            if(l1){
                carry += l1->val;
                l1 = l1->next;
            }
            if(l2){
                carry += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(carry%10);
            cur = cur->next;
            carry /= 10;
        }

        if(carry){
            cur->next = new ListNode(carry);
        }

        return dummy->next;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //memory management
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;
        int carry = 0;
        while(l1 && l2){
            if(l1) carry += l1->val;
            l1 = l1->next;
            if(l2) carry += l2->val;
            l2 = l2->next;
            dummy->next = new ListNode(carry%10);
            dummy = dummy->next;
            carry /= 10;
        }

        while(l1){
            if(l1)carry += l1->val;
            l1 = l1->next;
            dummy->next = new ListNode(carry%10);
            dummy = dummy->next;
            carry /= 10;
        }

        while(l2){
            if(l2)carry += l2->val;
            l2 = l2->next;
            dummy->next = new ListNode(carry%10);
            dummy = dummy->next;
            carry /= 10;
        }

        if(carry){
            dummy->next = new ListNode(carry);
        }
        return head->next;
    }
};