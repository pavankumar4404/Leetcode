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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        dummy->next = head;
        while(temp){
            if(s.find(temp -> val) != s.end()){
                prev->next = temp->next;
            }
            else {
                prev = temp;
            }
            
            temp=temp->next;
        }
        return dummy->next;
    }
};