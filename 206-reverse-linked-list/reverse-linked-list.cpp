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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
          return head;
        ListNode* newhead = head;
        ListNode* tail = head;
        while(tail->next!=NULL)
        {
            ListNode* temp = newhead;
            newhead =tail->next;
            tail->next=tail->next->next;
            newhead->next= temp;
        }
        return newhead;

    }
};