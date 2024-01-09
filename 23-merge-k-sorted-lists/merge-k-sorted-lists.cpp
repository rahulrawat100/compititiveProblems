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
    ListNode* Merge(vector<ListNode*>& lists, int i, int j)
    {
        if(i==j)
          return lists[i];
        else
        {
            int mid = i+(j-i)/2;
            ListNode* A= Merge(lists, i, mid);
            ListNode* B= Merge(lists, mid+1, j);
            return merged(A, B); 
        }  
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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n= lists.size();
        if(n==0)return NULL;
        return Merge(lists, 0, n-1);
    }
};