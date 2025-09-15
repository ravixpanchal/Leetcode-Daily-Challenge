class Solution {
public:
    unordered_set<string> exactSet;
    unordered_map<string,string> caseMp;
    unordered_map<string,string> vowelMp;
   
    string toLower(string &s){
        string result = s;
        for(char &ch: result){
            ch = tolower(ch);
        }
        return result;
    }

    string replaceVowel(string &s){
        string result = s;
        for(char &ch: result){
            if(ch=='a' || ch=='i' || ch=='e' || ch=='o' || ch=='u'){
                ch='*';
            }
        }
        return result;
    }

    string checkForMatch(string &query){
        if(exactSet.count(query)){
            return query;
        }

        // case error check
        string lowercase = toLower(query);
        if(caseMp.count(lowercase)){
            return caseMp[lowercase];
        }

        // vowel error check
        string vowelcase = replaceVowel(lowercase);
        if(vowelMp.count(vowelcase)){
            return vowelMp[vowelcase];
        }

        return "";
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        exactSet.clear();
        caseMp.clear();
        vowelMp.clear();

        for(string word: wordlist){
            exactSet.insert(word);

            string lowercase = toLower(word);
            if(caseMp.find(lowercase) == caseMp.end()){
                caseMp[lowercase] = word;
            }

            string vowelcase = replaceVowel(lowercase);
            if(vowelMp.find(vowelcase) == vowelMp.end()){
                vowelMp[vowelcase] = word;
            }
        }

        vector<string> ans;
        for(string query: queries){
            ans.push_back(checkForMatch(query));
        }

        return ans;
    }
};
