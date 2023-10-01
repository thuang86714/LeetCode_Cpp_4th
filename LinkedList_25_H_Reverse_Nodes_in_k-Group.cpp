/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

Follow-up: Can you solve the problem in O(1) extra memory space?
*/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //SunHaozhe, Iterative Solution SC O(1)
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *before = dummy;
        ListNode *after = head;
        ListNode *cur = NULL;
        ListNode *prev = NULL;
        ListNode *next = NULL;
        while(true){
            //whther we have entered the left-out group
            ListNode *ptr = after;
            for(int i = 0; i < k; i++){
                if(!ptr)return dummy->next;
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