class Solution {
public:

    int poorPigs(int buckets, int mTD, int mTT) {
        int tries = mTT/mTD;
        return ceil(log2(buckets)/log2(tries+1));
    }
};