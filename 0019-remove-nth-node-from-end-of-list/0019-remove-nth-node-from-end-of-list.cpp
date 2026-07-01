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
        ListNode* temp = head;
        if(head==NULL || head->next==NULL) return NULL;
        int cnt = 0;
        while (temp != NULL){
            cnt++;
            temp=temp->next;
        }
        if(n==cnt) {
            temp=head;
            head=head->next;
            delete temp;
        }
        int res = cnt - n;
        temp=head;
        while(temp!=NULL){
            res--;
            if(res==0){
                ListNode*deleteNode=temp->next;
                temp->next=temp->next->next;
                delete deleteNode;
            }
            temp=temp->next;
        }
        return head;
    }
};