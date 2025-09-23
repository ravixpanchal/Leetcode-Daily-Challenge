class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>m;//element,frequency
        int maxFreq=0;
        for(auto &i: nums){
            m[i]++;
            maxFreq=max(maxFreq,m[i]);
        }
        
        int ans=0;

        for(auto &p: m){
            if(p.second==maxFreq){
                ans+=p.second;
            }
        }


       return ans; 
    }
};