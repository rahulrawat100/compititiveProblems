class Spreadsheet {
public:
    vector<vector<int>> D;
    Spreadsheet(int rows) {
        D.assign(26, vector<int>(rows, 0));
    }
    
    void setCell(string cell, int value) {
        int r = cell[0]-'A';
        int c = (cell[1]-'0');
        if(cell.size()>2)
            c = c*10+(cell[2]-'0');
        if(cell.size()>3)
            c = c*10+(cell[3]-'0');
        D[r][c-1]=value;
    }
    
    void resetCell(string cell) {
                int r = cell[0]-'A';
                int c = (cell[1]-'0');
        if(cell.size()>2)
            c = c*10+(cell[2]-'0');
        if(cell.size()>3)
            c = c*10+(cell[3]-'0');     
        D[r][c-1]=0;
    }
    
    int get(string cell)
    {
        int val=0;
      //  cout<<cell<<"  ";
        for(int i=0; i<cell.size(); i++)
        {
            if(cell[i]-'0'>9)
              {
                val=-1;
                break;
              }
              val=val*10+(cell[i]-'0');
        }
        if(val>=0)return val;
                int r = cell[0]-'A';
        int c = (cell[1]-'0');
        if(cell.size()>2)
            c = c*10+(cell[2]-'0');
        if(cell.size()>3)
            c = c*10+(cell[3]-'0');    
          //  cout<<r<<"  "<<c<<endl;
        return D[r][c-1];
    }
    int getValue(string formula) {
                string cell1="";
                int i=1;
                for(; i<formula.size(); i++)
                {
                    if(formula[i]=='+')
                        break;
                    cell1+=formula[i];    
                }
                i++;
                string cell2="";
                for(; i<formula.size(); i++)
                {    
                    cell2+=formula[i];    
                }
              //  cout<<cell1<<" "<<cell2<<endl;
                return get(cell1) + get(cell2); 


    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */