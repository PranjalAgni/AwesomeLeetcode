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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        vector<int> linkedList;
        ListNode* temp = head;
        while (temp != NULL) {
            linkedList.push_back(temp->val);
            temp = temp->next;
        }

        int len = linkedList.size();
        int idx = 0;
        int curr = INT_MIN;
        bool isInit = true;
        for (int i = 0; i < len - 1; i++) {
            if (linkedList[i] != linkedList[i + 1]) {
                if (curr != linkedList[i] || isInit) {
                    linkedList[idx++] = linkedList[i];
                }
            } else {
                isInit = false;
                curr = linkedList[i];
            }
        }

        if (curr != linkedList[len - 1]) {
            linkedList[idx++] = linkedList[len - 1];
        }

        len = idx;

        ListNode* newHead = NULL;
        ListNode* ans = NULL;
        for (int i = 0; i < idx; i++) {
            ListNode* newTemp = new ListNode(linkedList[i]);

            if (newHead == NULL) {
                newHead = newTemp;
                ans = newHead;
            } else {
                newHead->next = newTemp;
                newHead = newHead->next;
            }
        }

        return ans;
    }
};