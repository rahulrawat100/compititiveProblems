class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        int left=0;
        int right=0;
        int rcount=0;
        for(int i=0; i<n; i++)
        {
            right+=boxes[i]=='1'?i:0;
            rcount+=boxes[i]=='1'?1:0;
        }
        int lcount=0;

        vector<int> res(n, 0);
        
        for(int i=0; i<n; i++)
        {
            rcount-=boxes[i]=='1'?1:0;
            res[i]=left+right;
            lcount+=boxes[i]=='1'?1:0;
            left+=lcount;
            right-=rcount;
        }
        return res;

        
    }
};