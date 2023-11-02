#include <queue>
#include <utility>
#include <cctype>
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

using PairItem = pair<int, ListNode*>;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<PairItem, vector<PairItem>, greater<PairItem>> pq;
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        for(int i = 0; i < lists.size(); i++){
            while(lists[i]){
                pq.push({lists[i]->val, lists[i]});
                lists[i] = lists[i]->next;
            }
        }

        while(!pq.empty()){
            ListNode *node = pq.top().second;
            cur->next = node;
            cur = cur->next;
            pq.pop();
        }
        cur->next = NULL;
        return dummy->next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> tempVec;
        for(int i = 0; i < lists.size(); i++){
            while(lists[i]){
                tempVec.push_back(lists[i]);
                lists[i] = lists[i]->next;
            }
        }

        auto cmp = [&](const ListNode *A, const ListNode *B){
            return A->val < B->val;
        };

        sort(tempVec.begin(), tempVec.end(), cmp);

        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;
        for(auto &node:tempVec){
            cur->next = node;
            cur = cur->next;
        }
        cur->next= NULL;

        return dummy->next;
    }
};