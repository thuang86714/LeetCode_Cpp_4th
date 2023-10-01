/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
 

Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.

*/


#include <queue>
#include <vector>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //credit to mingjun and mstest
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        for(auto l:lists){
            if(l){
                q.push(l);
            }
        }

        ListNode dummy(0);
        ListNode *cur = &dummy;
        while(q.size()){
            ListNode *top = q.top();
            q.pop();
            cur->next = top;
            cur = cur->next;
            if(top->next){
                q.push(top->next);
            }
        }
        return dummy.next;
    }

    struct compare{
        bool operator()(const ListNode *l1, ListNode *l2){
            return l1->val > l2->val;
        }
    };
};

