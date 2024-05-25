class Node
{
    public:
    Node* child[26];
    bool ends=false;
};
class Solution {
public:
    Node* root;

    void insert1(string& words)
    {
         int n =words.size();
         Node* temp = root;
         for(int i=0; i<n; i++)
         {
            int ind=words[i]-'a';
            //cout<<ind<<endl;
            if(temp->child[ind]==NULL)
               temp->child[ind]= new Node();
            temp=temp->child[ind];   
         }
         temp->ends=true;
    }

    void calc(string& s, int i, string curr, string ans, vector<string>& res, Node* temp)
    {
        cout<<i<<"  "<<curr<<" _ "<<ans<<endl;
        if(i==s.size()-1)
        {
            if(temp->ends)
            {
                if(ans.size()==0)
                calc(s, i, "", ans+curr, res, root);
               else 
                calc(s, i, "", ans+" "+curr, res, root);
            }
            int ind=s[i]-'a';
            if(temp->child[ind]!=NULL&& temp->child[ind]->ends)
            {
                curr+=s[i];
                if(ans.size()==0)
                ans+=curr;
              else
                ans+=" "+curr;  
                res.push_back(ans);
            }
        }
        else
        {
            int ind=s[i]-'a';
            if(temp->ends)
            {
                if(ans.size()==0)
                calc(s, i, "", ans+curr, res, root);
               else 
                calc(s, i, "", ans+" "+curr, res, root);
            }
             if(temp->child[ind]==NULL)
               return;
            calc(s, i+1, curr+s[i], ans, res, temp->child[ind]);
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = wordDict.size();
        root = new Node();
        for(int i=0; i<n; i++)
        {
            insert1(wordDict[i]);
        }
        // cout<<"serach  "<<endl;
        vector<string> res;
        calc(s, 0, "", "", res, root);
        return res;
    }
};