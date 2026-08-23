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
#define node ListNode
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return NULL;
        int n=1;
        node*last=head;
        while(last->next!=NULL){
            n++;
            last=last->next;
        }
        k=k%n;
        if(k==0)return head;
        node*t=head;
        int count=1;
        while(t!=NULL){
            if(count==(n-k)){
                break;
            }
            count++;
            t=t->next;
        }
        last->next= head;
        node*res=t->next;
        t->next=NULL;
        return res;
    }
};