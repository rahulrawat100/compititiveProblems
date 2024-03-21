public class Solution {
    public int MinCostConnectPoints(int[][] points) {
        var PQ = new PriorityQueue<int, int>();
        int n =points.Count();
        bool[] vis = new bool[n];

        vis[0]=true;

        for(int i=1; i<n; i++)
        {
            int x = points[i][0]-points[0][0];
            int y = points[i][1]-points[0][1];
            PQ.Enqueue(i, Math.Abs(x)+Math.Abs(y));
        }

        int count=1;
        int dis=0;
        while(count<n)
        {
                 //Console.WriteLine(PQ.Peek());
            while(vis[PQ.Peek()])
            {
                //Console.WriteLine(PQ.Peek());
                PQ.Dequeue();
            }

            PQ.TryPeek(out int p, out int priority);
            dis+=priority;
            PQ.Dequeue();
            vis[p]=true;
        for(int i=0; i<n; i++)
        {
            if(p==i || vis[i])continue;
            int x = points[i][0]-points[p][0];
            int y = points[i][1]-points[p][1];
            PQ.Enqueue(i, Math.Abs(x)+Math.Abs(y));
        }
        count++;
        }
        return dis;
    }
}