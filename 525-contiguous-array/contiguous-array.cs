public class Solution {
    public int FindMaxLength(int[] nums) {
        int n = nums.Count();
        Dictionary<int, List<int>> D = new Dictionary<int, List<int>>();
        int count=0;
        D.Add(0, new List<int>(){-1});
        int res=0;
        for(int i=0; i<n; i++)
        {
           count+=nums[i]==1?1:-1;
           //Console.WriteLine(count);
           if(D.ContainsKey(count))
           {
              res=Math.Max(res, i-D[count][0]);
              D[count].Add(i);
           }
           else
              D.Add(count, new List<int>(){i});
        }
        return res;

        
    }
}
