class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dis = max(abs(fx-sx), abs(fy-sy));
        if(dis==0&&t==1)return false;
        return dis<=t;
    }
};

   


            