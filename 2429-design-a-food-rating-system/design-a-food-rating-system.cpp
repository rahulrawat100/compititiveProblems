class FoodRatings {
public:
     unordered_map<string, set<pair<int, string>>> D; 
     unordered_map<string, string> E;
     unordered_map<string, int> F;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        int n =foods.size();

        for(int i=0; i<n; i++)
        {
            D[cuisines[i]].insert({ratings[i], foods[i]});
            E[foods[i]]=cuisines[i];
            F[foods[i]]=ratings[i];
        }
        cout<<"**"<<endl;
    }
    
    void changeRating(string food, int newRating) {
        string c = E[food];
        cout<<food<<"  "<<c<<endl;
        int r = F[food];
        F[food]=newRating;
        D[c].erase({r, food});
        D[c].insert({newRating, food});
        cout<<c<<"  "<<D[c].size()<<endl;
    }
    
    string highestRated(string cuisine) {

        auto it = D[cuisine].end();
        it--;
        int r=it->first;
        //cout<<cuisine<<"  "<<r<<endl;
        string res=it->second;
        while(it!=D[cuisine].begin()&&it->first==r)
        {
            res=it->second;
          //  cout<<res<<endl;
            it--;
        }
        return res;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */