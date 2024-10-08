class AllOne {
public:
    unordered_map<long long, string> codeToStr;
    unordered_map<long long, int> freq;
    map<int, unordered_set<long long>> freqToStr;
    AllOne() {
        
    }
    
    long long GetCode(string str)
    {
       int n = str.size();
       long long res=0;
       for(int i=0;i<n; i++)
       {
          res= res*27+(str[i]-'a'+1);
       }
       
       return res;
    }

    void inc(string key) {
       long long code = GetCode(key);
       codeToStr[code]=key;
       freq[code]++;
    //    cout<<key<<"  "<<code<<" i "<<freq[code]<<endl;
       if(freq[code]==1)
       {
          freqToStr[1].insert(code);
        if(freqToStr[1].size()==0)
             freqToStr.erase(1);
       }    
       else
       {
          freqToStr[freq[code]-1].erase(code);
          if(freqToStr[freq[code]-1].size()==0)
             freqToStr.erase(freq[code]-1);
          freqToStr[freq[code]].insert(code);
       }
    }
    
    void dec(string key) {
       long long code = GetCode(key);
       freq[code]--;
    //    cout<<key<<"  "<<code<<" d "<<freq[code]<<endl;
       if(freq[code]==0)
       {
          freqToStr[1].erase(code);
          if(freqToStr[1].size()==0)
             freqToStr.erase(1);
       }    
       else
       {
          freqToStr[freq[code]+1].erase(code);
         if(freqToStr[freq[code]+1].size()==0)
             freqToStr.erase(freq[code]+1);
          freqToStr[freq[code]].insert(code);
       }
    }
    
    string getMinKey() {
        if(freqToStr.size()==0)
           return "";
        auto it = freqToStr.begin();
      // cout<<it->first<<"  "<<it->second.size()<<endl;
        long long code = *(it->second.begin());
    //   cout<<"min  "<<codeToStr[code]<<endl;
        return codeToStr[code];
    }
    
    string getMaxKey() {
        if(freqToStr.size()==0)
           return "";
        auto it = freqToStr.end();
        it--;
      //  cout<<it->first<<" max "<<it->second.size()<<endl;
        long long code = *(it->second.begin());
        //cout<<"max  "<<codeToStr[code]<<endl;
        return codeToStr[code];
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */