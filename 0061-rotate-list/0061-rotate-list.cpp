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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        int n = 1;
        ListNode* temp = head;
        while(temp->next){
            temp = temp->next;
            n++;
        }
        k = k % n;
        if(k == 0) return head;
        int i = 1;
        ListNode* it = head;
        while(i < n-k){
            i++;
            it = it -> next;
        }
        ListNode* newHead = it->next;
        it->next = NULL;
        temp->next = head;
        return newHead;
    }
};