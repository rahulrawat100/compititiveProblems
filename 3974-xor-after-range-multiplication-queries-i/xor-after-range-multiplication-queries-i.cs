public class Solution {
    public int XorAfterQueries(int[] nums, int[][] queries) {
        int mod = (int)Math.Pow(10, 9)+7;
        List<long> arr = new List<long>(nums.Length);
        foreach(var num in nums)
        {
            arr.Add(num);
        }
        foreach(var q in queries)
        {
                int l = q[0];
                int r = q[1];
                int k = q[2];
                int v = q[3];
            for(int i=l; i<=r; i+=k)
            {
                arr[i]%=mod;
                arr[i]=(arr[i]*v)%mod;
            }
        }

        long res=0;
        nums.Sort();
        foreach(var num in arr)
        {
            res=res^num;
        }
        return (int)res;
    }
}