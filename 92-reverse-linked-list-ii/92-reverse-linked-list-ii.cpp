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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* root = new ListNode(-1, head);
        ListNode* keep = root;
        while (left > 1) {
            --left;
            --right;
            root = root->next;
        }
        
        stack<int> S;
        ListNode* tmp = root;
        while (left <= right) {
            S.push(tmp->next->val);
            tmp = tmp->next;
            ++left;
        }
        
        while (!S.empty()) {
            root->next = new ListNode(S.top()); S.pop();
            root = root->next;
        }
        
        root->next = tmp->next;
        
        return keep->next;
    }
};