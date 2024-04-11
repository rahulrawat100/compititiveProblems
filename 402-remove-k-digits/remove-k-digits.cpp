class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
         if(n==k)
           return "0";
        priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pq;

        int i=0;
        while(i<=k)
        {
            pq.push({num[i], i});
            i++;
        }

        string res="";
        int prev=-1;
        while(i<=n)
        {
            if(!pq.empty()&&k>0)
            {
            while(pq.top().second<prev)
            {
                pq.pop();
            }
            pair<char, int> p = pq.top();
            pq.pop();
            if(res.size()>0||p.first!='0')
            res+=p.first;
            k-=p.second- prev-1;
            prev=p.second;
             cout<<p.first<<"  "<<p.second<<endl;
            }
            if(i<n&&k>0)
            pq.push({num[i], i});
          else
              break;  
            i++;
        }
         prev++;
        while(k==0&&prev<n)
        {
            if(res.size()>0||num[prev]!='0')
            res+=num[prev];
            prev++;
        }
        if(res.size()==0)return "0";
        return res;

    }
};