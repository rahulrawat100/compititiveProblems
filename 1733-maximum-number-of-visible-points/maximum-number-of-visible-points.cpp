class Solution {
public:
    bool IsLessThan(double A, double B)
    {
        if(A<B)
          return true;
         if(abs(A-B)<0.001)
          return true;
        return false;   
    }
    bool IsGreaterThan(double A, double B)
    {
        if(A>B)
          return true;
         if(abs(A-B)<0.001)
          return true;
        return false;   
    }
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> angles;

        int n = points.size();
        int concurr=0;
        for(int i=0; i<n; i++)
        {
            if(points[i][0]==location[0])
            {
              if(points[i][1]>location[1])  
                 angles.push_back(90);
               else if(points[i][1]<location[1])
                  angles.push_back(270);
                else
                   concurr++;      
            } 
            else if(points[i][1]==location[1])
            {
              if(points[i][0]>location[0])  
                 angles.push_back(0);
               else if(points[i][0]<location[0])
                  angles.push_back(180);
                else
                   concurr++;      
            } 
            else
              {
                  double d = ((double)points[i][1]-location[1])/(points[i][0]-location[0]);
                  d=(180*113*atan(d))/355;
                  if(points[i][0]<location[0]&&points[i][1]<location[1])
                     d+=180;
                  else if(points[i][0]<location[0])
                     d+=180;
                  else if(points[i][1]<location[1])
                     d+=360;      
                  angles.push_back(d);
              }  
              //cout<<angles.size()<<"  ";
        }
        sort(angles.begin(), angles.end());
        int res=0;
        // for(int i=0; i<angles.size(); i++)
        // {
        //     cout<<angles[i]<<"  " ;
        // }
        // cout<<endl;
        int count=1;
        int lim=1;
        bool f=true;
        for(int i=0; i<angles.size(); i++)
        {
            double high=(angles[i]+angle);
            if(f&high>360)
            {
               high-=360;
               lim=0;
               count=angles.size()-i;
               f=false;
            }  
            else if(high>360)
            {
                high=high-360;
            }
            for(int j=lim; j<angles.size(); j++)
            {
                 if(angles[j]<=high)
                    count++;
                  else
                    break;
                  lim=j+1;       
            }
            res=max(res, count);
            count--;
            // cout<<i<<"   "<<count<<"   "<<endl;;
        }
        return res+concurr;
    }
};

       //39.0194  39.629  41.3785  45  48.0128 