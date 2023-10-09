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
    ListNode* sortList(ListNode* head) {
        //Divide and Conquer the whole linkedlist, recursively
        //then marge the divided linked list back, while maintain the order
        if(!head || !head->next)return head;
        ListNode *fast = head, *slow = head, *prev;
        
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;//prev would be the tail of the first half linked list
        //slow is the head, while fast is the tail of the 2nd half

        ListNode *L1 = sortList(head);
        ListNode *L2 = sortList(slow);

        return merge(L1, L2);
    }

    ListNode* merge(ListNode *L1, ListNode *L2){
        ListNode *dummy = new ListNode();
        ListNode *head = dummy;
        while(L1 && L2){
            if(L1->val > L2->val){
                dummy->next = new ListNode(L2->val);
                L2 = L2->next;
            }else{
                dummy->next = new ListNode(L1->val);
                L1 = L1->next;
            }
            dummy = dummy->next;
        }

        while(L1){
            dummy->next = new ListNode(L1->val);
            L1 = L1->next;
            dummy = dummy->next;
        }

        while(L2){
            dummy->next = new ListNode(L2->val);
            L2 = L2->next;
            dummy = dummy->next;
        }
        return head->next;
    }
};