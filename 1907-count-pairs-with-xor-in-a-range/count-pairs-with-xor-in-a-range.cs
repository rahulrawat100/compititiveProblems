public class Solution {
    public int CountPairs(int[] nums, int low, int high) {
        int n = nums.Length;

        int count=0;
         Array.Sort(nums);
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
               // if(nums[j]-nums[i]>high)
                 //  break;
                int x = nums[i]^nums[j];
                if(x>=low&&x<=high)
                   count++;
            }
        }
        return count;
    }
}