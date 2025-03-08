class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int black=0;
        for(int i=0; i<k; i++)
        {
            if(blocks[i]=='B')
               black++;
        }
        int ans= k-black;

        for(int i=k; i<n; i++)
        {
            if(blocks[i]=='B')
               black++;   

            if(blocks[i-k]=='B')
               black--; 
             ans= min(ans, k-black);  
        }
        return ans;
    }
};