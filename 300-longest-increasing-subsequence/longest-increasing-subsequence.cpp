bool compare(pair<int, int> P1, pair<int, int> P2)
{
    if(P1.first == P2.first)
    {
        if(P1.second>P2.second)
            return true;
    }
    if(P1.first<P2.first)
        return true;
    return false;
}

class Solution {
public:

void insert(int ind, int l, int r, int pos, int val, vector<int>& tree){

   if(l > pos || r < pos)return;
   
          
   if(l == r){
       tree[ind] = val;
       return;
   }
   int mid = l +(r - l) / 2;
   insert(2*ind+1, l, mid, pos, val, tree);
   insert(2*ind+2, mid+1, r, pos, val, tree);
   
   tree[ind] = max(tree[2*ind+1], tree[2*ind+2]);
}

int getMaxLen(int ind, int l, int r, int pos, vector<int>&tree){

    
    if(l > pos)return 0;
    if(r <= pos)return tree[ind];
    
       int mid = l+(r - l) / 2;
    
   return max(getMaxLen(2*ind+1, l, mid, pos, tree), getMaxLen(2*ind+2, mid+1, r, pos, tree)); 
}

int lengthOfLIS(vector<int>& nums) {
    vector<pair<int,int>> D ;
    int n = nums.size();
    for(int i=0; i<nums.size(); i++)
    {
        D.push_back({nums[i], i});
    }
    sort(D.begin(), D.end(), compare);
    
 //   int len = pow(2, (int)(ceil(sqrt(n))) + 1) - 1;
    vector<int> tree(40000, 0);
    for(auto x: D){
        insert(0, 0, n-1, x.second, getMaxLen(0, 0, n-1, x.second, tree)+1, tree);
    }
    
    return tree[0];
}
};

    
                    
    


  


    