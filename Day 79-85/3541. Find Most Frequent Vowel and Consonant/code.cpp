class Solution {
public:
    int maxFreqSum(string s) {
        vector<int>freq1(26);
        vector<int>freq2(26);

        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                freq1[ch-'a']++; //store the vowels 
            }else{
                freq2[ch-'a']++;
            }
        }

        int max1=0;
        int max2=0;

        for(int i=0;i<26;i++){
            max1=max(max1,freq1[i]);
            max2=max(max2,freq2[i]);
        }

        return max1+max2;
        
    }
};