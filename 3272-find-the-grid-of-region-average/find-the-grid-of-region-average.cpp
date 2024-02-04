class Solution {
public:
    bool check(vector<vector<int>>& image, int threshold, int x, int y)
    {
        for(int i=0; i<=2; i++)
        {
            for(int j=0; j<=2; j++)
            {
                int a=x+i;
                int b=y+j;
                
                if(i==0)
                {
                    if(j==0)
                    {
                        if(abs(image[a][b]-image[a][b+1])>threshold || abs(image[a][b]-image[a+1][b])>threshold)
                            return false;
                    }
                    else if(j==2)
                    {
                        if(abs(image[a][b]-image[a][b-1])>threshold || abs(image[a][b]-image[a+1][b])>threshold)
                            return false;
                    }
                    else
                    {
                       if(abs(image[a][b]-image[a][b+1])>threshold || abs(image[a][b]-image[a][b-1])>threshold || abs(image[a][b]-image[a+1][b])>threshold)
                            return false;
                    }
                    
                }
                else if(i==2)
                {
                    if(j==0)
                    {
                        if(abs(image[a][b]-image[a][b+1])>threshold || abs(image[a][b]-image[a-1][b])>threshold)
                            return false;
                    }
                    else if(j==2)
                    {
                        if(abs(image[a][b]-image[a][b-1])>threshold || abs(image[a][b]-image[a-1][b])>threshold)
                            return false;
                    }
                    else
                    {
                       if(abs(image[a][b]-image[a][b+1])>threshold || abs(image[a][b]-image[a][b-1])>threshold || abs(image[a][b]-image[a-1][b])>threshold)
                            return false;
                    }
                }
                else
                {
                    if(j==0)
                    {
                        if(abs(image[a][b]-image[a][b+1])>threshold || abs(image[a][b]-image[a-1][b])>threshold || abs(image[a][b]-image[a+1][b])>threshold)
                            return false;
                    }
                    else if(j==2)
                    {
                        if(abs(image[a][b]-image[a][b-1])>threshold || abs(image[a][b]-image[a-1][b])>threshold || abs(image[a][b]-image[a+1][b])>threshold)
                            return false;
                    }
                    else
                    {
                       if(abs(image[a][b]-image[a][b+1])>threshold || abs(image[a][b]-image[a][b-1])>threshold || abs(image[a][b]-image[a-1][b])>threshold || abs(image[a][b]-image[a+1][b])>threshold)
                            return false;
                    }
                }
            }
        }
        return true;
    }
    
    int sumed(vector<vector<int>>& image, int i, int j)
    {
        int s=0;
        for(int a=0; a<3;a++)
        {
            for(int b=0; b<3; b++)
            {
                s+=image[a+i][b+j];
            }
        }
        return s;
    }
    
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> sum(m, vector<int>(n, 0));
                vector<vector<int>> count(m, vector<int>(n, 0));
        for(int i=0; i<m-2; i++)
        {
            for(int j=0; j<n-2; j++)
            {
                if(check(image, threshold, i, j))
                {
                   int s=sumed(image, i, j);
                   s=s/9;
                           for(int a=0; a<3;a++)
                     {
                           for(int b=0; b<3; b++)
                          {
                          sum[a+i][b+j]+=s;
                               count[a+i][b+j]++;
                          }
                      }
                }
            }
        }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
               if(count[i][j]>0) 
                sum[i][j]/=count[i][j];
              else
                 sum[i][j]=image[i][j];
            }
        }
        return sum;
    }
};
