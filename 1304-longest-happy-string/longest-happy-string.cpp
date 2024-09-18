class Solution {
public:
    string calc(priority_queue<pair<int, char>>& pq, char prev, int count)
    {
        if(pq.size()==0)
          return "";
        else
        {
            if(count==2)
            {
                if(pq.size()==1)
                  return "";
                if(pq.top().second==prev)
                {
                  pair<int, char> p1= pq.top();
                   pq.pop();
                 pair<int, char> p2= pq.top();
                   pq.pop();
                   p2.first--;
                   if(p2.first>0)
                   pq.push(p2);
                   pq.push(p1);
                   return p2.second+calc(pq, p2.second, 1);
                }  
            }
            pair<int, char> p1= pq.top();
            pq.pop();
            p1.first--;
           if(p1.first>0) 
            pq.push(p1);
            return p1.second+calc(pq, p1.second, p1.second==prev?count+1:1);
        }  
    }
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
   if(a>0)
        pq.push({a, 'a'});
      if(b>0)  
        pq.push({b, 'b'});
       if(c>0) 
        pq.push({c, 'c'});
        return calc(pq, 'd', 0);
    }
};