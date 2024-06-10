class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> D;
        int n= hand.size();

        for(int i=0; i<n; i++)
        {
            D[hand[i]]++;
        }

        unordered_map<int, int> end;
        int needed=0;
        for(auto it: D)
        {
           if(needed>it.second)
              return false;
           else
           {
              end[it.first+groupSize-1]=it.second-needed;
              needed=it.second-end[it.first];
           }     
        }
        
        return needed==0;
    }
};