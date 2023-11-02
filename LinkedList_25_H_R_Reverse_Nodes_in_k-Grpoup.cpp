#include <vector>
#include <cstddef>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //credit to SunHaozhe, Iterative Solution SC O(1)
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *before = dummy;
        ListNode *after = head;
        ListNode *next = NULL;
        ListNode *prev = NULL;
        ListNode *cur = NULL;

        while(true){
            //to check whether we have enter the left-out group
            ListNode *ptr = after;
            for(int i = 0; i < k; i++){
                if(!ptr){
                    return dummy->next;
                }
                ptr = ptr->next;
            }

            cur = after;
            prev = before;
            for(int i = 0; i < k; i++){
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            after->next = cur;
            before->next = prev;
            before = after;
            after = cur;
        }

    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //credit to jacklee20499, TC O(n), SC O(n)
        vector<ListNode*> tempVec;
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;

        while(head){
            tempVec.push_back(head);
            head = head->next;

            if(tempVec.size() == k){
                reverse(tempVec.begin(), tempVec.end());
                for(auto &node:tempVec){
                    cur->next = node;
                    cur = cur->next;
                }
                tempVec.clear();
            }
        }

        //handle the last group which is smaller than k
        for(auto &node: tempVec){
            cur->next = node;
            cur = cur->next;
        }
        cur->next = NULL;
        return dummy->next;
    }
};