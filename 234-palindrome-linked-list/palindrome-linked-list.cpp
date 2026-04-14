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
    private:
     ListNode* reverseLL(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverseLL(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
     }
public:
    bool isPalindrome(ListNode* head) {

        if(head == NULL || head->next == NULL) return true;

         ListNode* slow=head,*fast=head;
         while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
         }
         ListNode* newHead = reverseLL(slow->next);
         ListNode* rNode = newHead;
         slow=head;
         while(rNode){
        if(rNode->val != slow->val) {
            reverseLL(newHead);
            return false;
            }
            slow=slow->next;
            rNode = rNode->next;
         }

         reverseLL(newHead);

         return true;
    }
};