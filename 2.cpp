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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;
        ListNode* ans=l1,*head1=l1,*head2=l2;
        while(head1&&head2){
            head1=head1->next;
            head2=head2->next;
        }
        if(head2){
            l1=l2;
            l2=ans;
            ans=l1;
        }
        while(l1!=NULL&&l2!=NULL){
            l1->val=(l1->val+l2->val+c);
            c=(l1->val)/10;
            l1->val%=10;
            if(l1->next){
                l1=l1->next;
                l2=l2->next;
            }
            else{
                if(c!=0){
                    l1->next=new ListNode(c);
                    l1=l1->next;
                }
                l1=l1->next;
                l2=l2->next;
            }
        }
        if(l1){
            while(l1->next!=NULL&&c!=0){
                l1->val=(l1->val+c);
                c=(l1->val)/10;
                l1->val%=10;
                l1=l1->next;
            }
            if(c!=0){
                l1->val=(l1->val+c);
                c=(l1->val)/10;
                l1->val%=10;
                if(c!=0)
                    l1->next=new ListNode(c);
                return ans;
            }
        }
        return ans;
    }
};
