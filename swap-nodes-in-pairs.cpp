/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* remaning = head->next->next;
        ListNode* newhead = head->next;
        head->next->next = head;
        head->next = swapPairs(remaning);
        return newhead;
    }
};

// 2 -> 1 -> 3 -> 4 -> null
// 2 -> 1
// temp = 2
// 2-> 3
// 1->2
// 1 -> 2 -> 3