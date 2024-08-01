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
    ListNode* merge(ListNode* A, ListNode* B)
    {
        //cout<<A->val<<"  "<<B->val<<endl;
        if(A==NULL)
           return B;
        if(B==NULL)
           return A;   
        if(A->val<=B->val)
        {
            ListNode* head = A;
            ListNode* prev = A;
            while(A!=NULL&&A->val<=B->val)
            {
                prev=A;
                A=A->next;
            }
            prev->next=merge(A, B);
            return head;
        }
        else
        {
            ListNode* head = B;
            ListNode* prev = B;
            while(B!=NULL&&B->val<A->val)
            {
                prev=B;
                B=B->next;
            }
            prev->next=merge(A, B);
            return head;            
        }
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0)
           return NULL;
        ListNode* head=lists[0];
        for(int i=1; i<n; i++)
        {
            head = merge(head, lists[i]);
        }
        return head;
    }
};