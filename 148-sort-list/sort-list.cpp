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
    ListNode* merge(ListNode* A)
    {
        if(A==NULL)  return NULL;
        if(A->next==NULL)return A;
        ListNode* head1=A;
        ListNode* head2=A;
        ListNode* prev;
        while(head1!=NULL&&head1->next!=NULL)
        {
            head1=head1->next;
             head1=head1->next;
             prev=head2;
              head2=head2->next;
        }

        ListNode* X=A;
        ListNode* Y=head2;
        prev->next=NULL;

        X= merge(X);
        Y=merge(Y);
        return merged(X, Y);



    }

    ListNode* merged(ListNode* A, ListNode* B)
    {
        ListNode* res;
        if(A==NULL&&B==NULL)
          return NULL;
        else if(A==NULL)
          return B;
        else if(B==NULL)
          return A;    
        else if(A->val<B->val)
          {
              res=A;
              res->next=merged(A->next, B);
              return res;
          }
         else
         {
              res=B;
              res->next=merged(A, B->next);
              return res;
         } 
    }

    ListNode* sortList(ListNode* head) {
             return merge(head);
    }
};