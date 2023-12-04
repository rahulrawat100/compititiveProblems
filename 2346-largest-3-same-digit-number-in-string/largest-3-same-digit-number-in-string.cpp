class Solution {
public:
    string largestGoodInteger(string num) {
        char ch='a';
        for(int i=2; i<num.size(); i++)
        {
            if(num[i]==num[i-1]&&num[i-1]==num[i-2])
            {
                if(ch=='a'||ch<num[i])
                  ch=num[i];
            }

        }

        string res="";
        if(ch=='a')return res;
        res+=ch;
        res+=ch;
        res+=ch;
        return res;
    }
};