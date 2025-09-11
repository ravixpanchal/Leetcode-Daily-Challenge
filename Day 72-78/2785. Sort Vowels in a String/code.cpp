class Solution {
public:

int isVowel(const char& ch){
    return (ch=='A' or ch=='a' or ch=='E' or ch=='e' or ch=='I' or ch=='i' or ch=='O' or ch=='o' or ch=='U' or ch=='u');
}
    string sortVowels(string s) {
        int n=s.size();

        //step1: Count vowel frequency
        map<char,int>m;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                m[s[i]]++;
            }
        }

        vector<pair<char,int>>freq;

        for(pair<char,int>p:m){
            freq.push_back(p);
        }

        //step-2: Update the input string
        int pos=0;
        int i=0;

        while(i<n and pos<freq.size()){
            if(freq[pos].second==0){
                pos++;
                continue;
            }

            if(isVowel(s[i])){
                s[i]=freq[pos].first;
                freq[pos].second--;
            }
            i++;
        }
        return s;
        
    }
};