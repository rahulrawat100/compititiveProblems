class RangeModule {
public:
    vector<pair<int, int>> D;
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
    //    cout<<"add"<<left<<"  "<<right<<endl;
         int i=0;
         int n= D.size();
         if(n==0)
         {
           D.push_back({left, right});
           return;
         }
         if(left>D[n-1].second)
           {
               D.push_back({left, right});
               return;
           }
          if(right<D[0].first)
          {
              D.insert(D.begin(), {left, right});
              return;
          } 
          while(i<D.size())
          {
              
              if(D[i].second<left)
              {
                  i++;
                 continue;
              }
               else if(D[i].first>right)
                 break;
               else if(D[i].first<left&&D[i].second>=right)
                {
                          
                    return;
                }
               else if(left<=D[i].first&&right>=D[i].second)
               {
                   D.erase(D.begin()+i);
               }  
               else 
               {
                  D[i].first=min(D[i].first, left);
                  D[i].second=max(D[i].second, right);
                  left=D[i].first;
                  right=D[i].second;
               }     
          }
          D.insert(D.begin()+i, {left, right});
        //   for(int i=0; i<D.size();i++)
        //   {
        //       cout<<D[i].first<<"  "<<D[i].second<<",  ";
        //   }
        //   cout<<endl;
    }
    
    bool queryRange(int left, int right) {
        // cout<<"query   "<<left<<"  "<<right<<endl;;
        for(int i=0; i<D.size(); i++)
        {
            if(D[i].first<=left&&D[i].second>=right)
              return true;
        }
        // cout<<"  false"<<endl;
        return false;
    }
    
    void removeRange(int left, int right) {
     int i=0;
       // cout<<"remove   "<<left<<"  "<<right<<endl;
         int n= D.size();
         if(n==0)return;
         if(left>=D[n-1].second)
           {
               return;
           }
          if(right<D[0].first)
          {
              return;
          } 
          while(i<D.size())
          {
             // cout<<i<<endl;
              if(D[i].second<=left)
              {
                  i++;
                 continue;
              }
               else if(D[i].first>=right)
                 break;
               else if(D[i].first<=left&&D[i].second>=right)
                {
                    if(D[i].first==left)
                    {
                        D[i].first=right;
                        return;
                    }
                    if(D[i].second==right)
                    {
                        D[i].second=left;
                        return;
                    }
                    int t= D[i].second;
                    D[i].second=left;
                    if(t>right)
                    {
                       if(i==D.size()-1)
                       D.push_back({right, t});
                      else  
                       D.insert(D.begin()+i+1,{right, t});
                    }
                    i++;  
                }
               else if(left<=D[i].first&&right>=D[i].second)
               {
                   D.erase(D.begin()+i);
               }  
               else 
               {
                  if(D[i].first<left)
                  {
                      D[i].second=left;
                  }
                  else if(D[i].first>left)
                  {
                      D[i].first=right;
                  }
                  i++;
               }     
          }
        //   for(int i=0; i<D.size();i++)
        //   {
        //       cout<<D[i].first<<"  "<<D[i].second<<",  ";
        //   }
        //   cout<<endl;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */