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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans;
        if(list1==NULL&&list2==NULL)
          return NULL;
        else if(list1==NULL)
          return list2;
        else if(list2==NULL)
         return list1;
        else
        {
            if(list1->val<=list2->val)
            {
                ans=list1;
                list1=list1->next;
                ans->next=mergeTwoLists(list1, list2);
                return ans;
            }
            else
            {
                ans=list2;
                list2=list2->next;
                ans->next=mergeTwoLists(list1, list2);
                return ans;
            }
        } 
        return ans;    
    }
};