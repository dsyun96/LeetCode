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
    ListNode* partition(ListNode* head, int x) {
        ListNode* root = new ListNode(), *keep = root;
        
        queue<int> A, B;
        while (head) {
            if (head->val < x) A.push(head->val);
            else B.push(head->val);
            head = head->next;
        }
        
        while (!A.empty()) {
            root->next = new ListNode(A.front()); A.pop();
            root = root->next;
        }
        while (!B.empty()) {
            root->next = new ListNode(B.front()); B.pop();
            root = root->next;
        }
        
        return keep->next;
    }
};