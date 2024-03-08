class Solution {
public:
    void calc(vector<vector<int>>& adj, vector<int>& cost, vector<long long>& ans, int i, long long& A, long long& B, long long& C, long long& D, long long& E, long long& F)
    {
        if(ans[i]!=-1)
           return;
        else
        {
            ans[i]=0;
            long long a=INT_MIN;
          long long b=INT_MIN;
            long long c=INT_MIN;
            long long d=INT_MAX;
            long long e=INT_MAX;
            long long f=INT_MAX;


             for(int j=0; j<adj[i].size(); j++)
             {
                 calc(adj, cost, ans, adj[i][j], a, b, c, d, e, f);
             }
             int count=0;
             if(cost[i]>0)
             {
                 if(cost[i]>a)
                 {
                     c=b;
                     b=a;
                     a=cost[i];
                 }
                 else if(cost[i]>b)
                 {
                     c=b;
                     b=cost[i];
                 }
                 else if(cost[i]>c)
                 {
                     c=cost[i];
                 }
             }
             else
             {
                 if(cost[i]<d)
                 {
                     f=e;
                     e=d;
                     d=cost[i];
                 }
                 else if(cost[i]<e)
                 {
                     f=e;
                     e=cost[i];
                 }
                 else if(cost[i]<f)
                 {
                     f=cost[i];
                 }
             }
             if(a!=INT_MIN)
                count++;
              if(b!=INT_MIN)
                count++;
               if(c!=INT_MIN)
                count++;
                if(d!=INT_MAX)
                count++;
               if(e!=INT_MAX)
                count++;
                if(f!=INT_MAX)
                count++;
               if(count<3)
               {
                   ans[i]=1;
               }
               else
               {
                   long long prod=-1;
                   //cout<<a<<" "<<b<<"  "<<c<<endl;; 
                   if(a!=INT_MIN && b!=INT_MIN&& c!=INT_MIN)
                      prod=max(prod, a*b*c);
                    if(d!=INT_MAX&&e!=INT_MAX&&a!=INT_MIN)
                      prod=max(prod, d*e*a); 
                    if(prod<0)
                       ans[i]=0;
                    else
                       ans[i]=prod;        
               }
               priority_queue<long long> pq;
               pq.push(A);
               pq.push(B);
               pq.push(C);
               pq.push(a);
               pq.push(b);
               pq.push(c);
               A=pq.top();
                pq.pop();
               B=pq.top();
                pq.pop();
               C=pq.top();
                 pq.pop();

              while(!pq.empty())
              {
                  pq.pop();
              }        
             pq.push(-D);
               pq.push(-E);
               pq.push(-F);
               pq.push(-d);
               pq.push(-e);
               pq.push(-f);
               D=-pq.top();
                pq.pop();
               E=-pq.top();
                pq.pop();
               F=-pq.top();
                 pq.pop();
             // cout<<i<<"  "<<"-"<<A<<"  "<<B<<"  "<<C<<"  "<<D<<"  "<<E<<"  "<<F<<endl;   
        }   
    }

    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int m = edges.size();

        vector<vector<int>> adj(m+1);

        for(int i=0; i<m; i++)
        {
            int u= edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
         vector<long long> ans(m+1, -1);
                    long long A=INT_MIN;
            long long B=INT_MIN;
            long long C=INT_MIN;
            long long D=INT_MAX;
            long long E=INT_MAX;
            long long F=INT_MAX;
         calc(adj, cost, ans,0, A, B, C, D, E, F);
         return ans;

    }
};