/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int get(vector<ListNode*>& lists,ListNode* curr){
        int mn=0;
        for(int i=1;i<lists.size();i++){
            if(lists[mn]!=NULL){
                if(lists[i]!=NULL)
                    if(lists[i]->val<=lists[mn]->val)
                        mn=i;
            }
            else{
                mn=i;
            }
        }
        // ListNode *ans=*lists[mn];
        // lists[mn]=lists[mn]->next;
        return mn;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 40 min in
        // vector<int> in(lists.size(),0);
        vector<ListNode*> in=lists;
        if(lists.size()==0)
            return NULL;
        
        bool b=0;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)
                b=1;
        }
        if(!b)
            return NULL;
        ListNode* head,*ans;
        int mn=0;
        for(int i=1;i<lists.size();i++){
            if(in[mn]!=NULL){
                if(in[i]!=NULL)
                    if(in[i]->val<=in[mn]->val)
                        mn=i;
            }
            else{
                mn=i;
            }
        }
        head=ans=in[mn];
        in[mn]=in[mn]->next;
        // cout<<mn<<" ";//in[mn]->val;
        // return ans;
        int j;
        while(1){
            if(head==NULL)
                break;
            j=get(in,head);
            // cout<<j<<" " ;
            head->next=in[j];
            if(in[j]!=NULL)
            in[j]=in[j]->next;
            head=head->next;
            // cout<<head->val;
        }
        return ans;
    }
};
