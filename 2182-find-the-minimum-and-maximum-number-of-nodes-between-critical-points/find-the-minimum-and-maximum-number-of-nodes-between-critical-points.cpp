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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* H=head->next;
        ListNode* prev=head;
        vector<int> Ind;
        int i=1;
        
        while(H!=NULL &&H->next!=NULL)
        {
            if(H->val<prev->val && H->val<H->next->val)
                Ind.push_back(i);
            else if(H->val>prev->val && H->val>H->next->val)
                Ind.push_back(i);
            i++;
            prev=H;
            H=H->next;
        }
        vector<int> res(2, -1);
        if(Ind.size()<2)
            return res;
        res[0]=INT_MAX;
        for(int i=1; i<Ind.size(); i++)
        {
            res[0]=min(res[0], Ind[i]-Ind[i-1]);
        }
        
        res[1]=Ind[Ind.size()-1]-Ind[0];
        return res;
        
    }
};