class Solution {
public:
    bool check(string &s,unordered_map<char,int>&m){
        for(char ch:s){
            if(m.find(ch)!=m.end()){
                return false;
            }
        }
        return true;
    }

    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,int>m;
        for(auto ch: brokenLetters){
            m[ch]++;
        }

        string s="";
        int count=0;

        for(int i=0;i<text.size();i++){
            if(text[i]==' '){
                if(check(s,m)){
                    count++;
                }
                s="";
            }else{
                s+=text[i];
            }
        }
        if(check(s,m)){
            count++;
        }
        return count;
        
    }
};