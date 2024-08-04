class Solution {
public:

    int minFlips(vector<vector<int>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        int res=0;
        for(int i=0; i<m/2; i++)
        {
            for(int j=0;j<n/2;j++)
            {
                int count=0;
                count += grid[i][j];
                count += grid[i][n-1-j];
                count += grid[m-1-i][j];
                count += grid[m-1-i][n-1-j]; 
                if(count==1 || count==3)
                    res++;
                else if( count ==2)
                    res+=2;
                    
            }
        }
        if(m%2==0&&n%2==0)
          return res;
        int one=0;
        int chng=0;
        int pali=0;
        if(m%2==1)
        {
            for(int i=0; i<n/2; i++)
            {
                int count=grid[m/2][i];
                count+=grid[m/2][n-1-i];
                if(count==2)
                  pali++;
                else if(count==1)
                {  
                  one++;
                 chng++;
                }
            }
        }
       if(n%2==1)
        {
            for(int i=0; i<m/2; i++)
            {
                int count=grid[i][n/2];
                count+=grid[m-1-i][n/2];
                if(count==2)
                  pali++;
                else if(count==1)
                {  
                  one++;
                chng++;
                }
            }
        }
        int mid=0;
        if(m%2==1&&n%2==1)
          mid+=grid[m/2][n/2];
        if(pali%2==1)
        {
            if(chng==0)
              return res+2+mid;
               
        }
         //cout<<res<<" "<<chng<<"  "<<mid<<endl;
        return res+chng+mid;

        


    }
};
// [[1,0,0]
// ,[0,1,0]
// ,[0,0,1]]