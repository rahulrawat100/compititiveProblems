class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> D;

        for(int i=0; i<bills.size(); i++)
        {
            if(bills[i]==5)
                D[5]++;
            else if(bills[i]==10)
            {
                if(D[5]==0)
                  return false;
                D[5]--;
                D[10]++;  
            }
            else
            {
                if(D[5]==0)
                  return false;
                if(D[5]<3&&D[10]==0)
                  return false;
                if(D[10]>0)
                {
                    D[5]--;
                    D[10]--;
                } 
                else
                     D[5]-=3;      
            }    
        }
        return true;
    }
};