public class Solution {
    public int[][] Insert(int[][] intervals, int[] newInterval) {
        int start = newInterval[0];
        int end = newInterval[1];

        int n = intervals.Count();
        List<List<int>> D = new List<List<int>>();
        for(int i=0; i<n; i++)
        {
            if(start==-1||intervals[i][1]<start)
              {
                D.Add(new List<int>{intervals[i][0],intervals[i][1]});
              }
            else if(intervals[i][0]>end)
            {
               D.Add(new List<int>{start, end});
               start=-1;
               end=-1;
               D.Add(new List<int>{intervals[i][0],intervals[i][1]});
            }
            else
              {
                  start = Math.Min(start, intervals[i][0]);
                  end = Math.Max(end, intervals[i][1]);
              }  
        }
                if(start!=-1)
            D.Add(new List<int>{start, end});
        int[][] arr = new int [D.Count()][];
        for(int i=0; i<D.Count(); i++)
        {
            arr[i] = new int[2];
            arr[i][0]=D[i][0];
            arr[i][1]=D[i][1];
        }
        return arr;
    }
}