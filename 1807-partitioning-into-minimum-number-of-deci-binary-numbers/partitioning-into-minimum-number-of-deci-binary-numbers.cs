public class Solution {
    public int MinPartitions(string n) {
        int res=1;
        foreach(var ch in n)
        {
            int dig = ch-'0';
            res=Math.Max(res, dig);
        }
        return res;
    }
}