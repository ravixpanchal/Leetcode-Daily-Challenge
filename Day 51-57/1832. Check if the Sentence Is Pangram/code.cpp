class Solution {
public:
    bool checkIfPangram(string sentence) {
        for(char ch='a';ch<='z';ch++){
            bool found=false;
            for(int i=0;i<=sentence.size();i++){
                if(ch==tolower(sentence[i])){
                    found=true;
                    break;
                }
            }

            if(found==false) return false;
        }
        return true;
        
    }
};