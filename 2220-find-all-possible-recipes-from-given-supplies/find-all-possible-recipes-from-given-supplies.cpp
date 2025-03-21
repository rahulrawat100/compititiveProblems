class Trie
{
    public:
    Trie* child[26];
    bool ends = false;
};
class Solution {
public:
    Trie* root;
    int count=0;
    unordered_map<string, bool> trav;
    void Insert(string s)
    {
        Trie* temp = root;
        for(int i=0; i<s.size(); i++)
        {
            int ind = s[i]-'a';
            if(temp->child[ind]==NULL)
               temp->child[ind]= new Trie();
            temp = temp->child[ind];   
        }
        temp->ends= true;
    }

    bool Contains(string s)
    {
        Trie* temp = root;
        for(int i=0; i<s.size(); i++)
        {
            int ind = s[i]-'a';
            if(temp->child[ind]==NULL)
               return false;
            temp = temp->child[ind];   
        }
        return temp->ends;
    }

    bool Check(vector<vector<string>>& ingredients,unordered_map<string, int>& D, vector<string>& recipes, int i, vector<string>& res)
    {
        int j=0;
        if(trav[recipes[i]])
           return Contains(recipes[i]);
        trav[recipes[i]]=true;   
           count++;
        while(j<ingredients[i].size())
        {
            if(D.find(ingredients[i][j])!=D.end())
            {
                if(!Check(ingredients, D, recipes, D[ingredients[i][j]], res))
                   break; 
            }
            else if(!Contains(ingredients[i][j]))
                break;
             j++;
        }
            if(j==ingredients[i].size()&&!Contains(recipes[i]))
            {
               Insert(recipes[i]);
               res.push_back(recipes[i]);
            }
            count--;
            return j == ingredients[i].size();
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        root= new Trie();

        for(int i=0; i<supplies.size(); i++)
        {
            Insert(supplies[i]);
        }
        unordered_map<string, int> D;
        vector<string> res;
        for(int i=0; i<recipes.size();i++)
        {
            D[recipes[i]]=i;
        }
        for(int i=0; i<recipes.size();i++)
        {
             Check(ingredients, D, recipes, i, res);
        }

        return  res;


    }
};