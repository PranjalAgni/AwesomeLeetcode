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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> linkedList;

        ListNode* temp = head;
        while (temp != NULL) {
            linkedList.push_back(temp->val);
            temp = temp->next;
        }

        int len = linkedList.size();
        vector<int> ansList(len);
        for (int i = 0; i < len; i++) {
            ansList[(i + k) % len] = linkedList[i];
        }

        int itr = 0;
        temp = head;
        while (temp != NULL) {
            temp->val = ansList[itr];
            itr += 1;
            temp = temp->next;
        }

        return head;
    }
};