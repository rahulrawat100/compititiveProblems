class Solution {
public:
     void calc(vector<vector<int>>& graph, int i, vector<int>& curr, vector<vector<int>>& ans)
     {
         if(i==graph.size()-1)
         {
            ans.push_back(curr);
            return;
         }
         if(graph[i].size()==0)
           return;
         else
         {
            for(int j=0; j<graph[i].size(); j++)
            {
                curr.push_back(graph[i][j]);
                calc(graph, graph[i][j], curr, ans);
                curr.pop_back();
            }
         }  
     }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> curr;
        curr.push_back(0);
        calc(graph, 0, curr, ans);
        return ans;
    }
};