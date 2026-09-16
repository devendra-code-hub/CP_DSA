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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int tn=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            tn++;
        }
        ListNode * d = new ListNode(0, head);
        temp=d;
         
        for(int i=0; i<(tn-n); i++){
            temp=temp->next;
        }
        ListNode* del = temp->next;
        temp->next=temp->next->next;
        delete del;
         
        return d->next;
        
    }
};