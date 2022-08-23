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
    bool isPalindrome(ListNode* head) {
        long long h1 = 0, h2 = 0, key = 1, inv = 60998152;
        const int MOD = 1e9 + 7;
        
        for (ListNode *p = head; p; p = p->next) {
            key = key * 541 % MOD;
            h1 = (h1 + p->val * key) % MOD;
            if (h1 < 0) h1 += MOD;
        }
        
        for (ListNode *p = head; p; p = p->next) {
            h2 = (h2 + p->val * key) % MOD;
            if (h2 < 0) h2 += MOD;
            key = key * inv % MOD;
        }
        
        return h1 == h2;
    }
};