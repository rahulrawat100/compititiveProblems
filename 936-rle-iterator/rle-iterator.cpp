class RLEIterator {
public:
    map<long long, int> D;
    long long curr=0;
    long long count=0;
    RLEIterator(vector<int>& encoding) {
        int n = encoding.size();
        for(int i=0; i<n; i+=2)
        {
            int freq= encoding[i];
            if(freq==0)continue;
            count+=freq;
            D[count]=encoding[i+1];
        }
    }
    
    int next(int n) {
        curr+=n;
                if(curr>count)return -1;
        auto it = D.lower_bound(curr);
        return it->second;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */