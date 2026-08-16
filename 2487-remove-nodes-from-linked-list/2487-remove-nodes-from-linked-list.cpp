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
    ListNode* solve(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* right = solve(head->next);
        if(right->val>head->val) return right;
        else{
            head->next = right;
            return head;
        }
    }
    ListNode* removeNodes(ListNode* head) {
        return solve(head);
        
    }
};