bool compare(vector<int>& A, vector<int>&B)
{
    if(A[1]!=B[1])
       return A[1]<B[1];  
     return A[0]<B[0];   
}
class Solution {
public:
    int calc(vector<vector<int>>& courses, int i, int curr,vector<vector<int>>& DP)
    {
        if(i==courses.size())
           return 0;
        if(DP[i][curr]!=-1)
           return DP[i][curr];   
                   //cout<<i<<"  "<<courses[i][0]<<" "<<courses[i][1]<<endl;
        if(curr+courses[i][0]<=courses[i][1])
          return DP[i][curr]=1+calc(courses, i+1, curr+courses[i][0], DP);   
        else
          return DP[i][curr]=calc(courses, i+1, curr, DP);  
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), compare);
        int n = courses.size();
        priority_queue<int> pq;
        int time=0;
        for(auto i:courses)
       {
           int dur=i[0];
           int lim=i[1];
           time+=dur;
           pq.push(dur);
           if(time>lim)
           {
              time-=pq.top();
              pq.pop();
           }
       }
       return pq.size();

    }
};