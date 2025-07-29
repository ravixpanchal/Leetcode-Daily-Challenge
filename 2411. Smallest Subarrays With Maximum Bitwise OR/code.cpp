class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        vector<int>nextSetBitPos(32,-1);

        //Step-1 : Solve right to left
        int maxOr=0;
        for(int i=n-1;i>=0;i--){
            maxOr|=nums[i]; //taking or with each element
            int curr=nums[i];
            int pos=0;
            while(curr){
                if(curr&1){
                    nextSetBitPos[pos]=i;
                }
                curr/=2; //convert into binary
                pos++;
            }
            int maxIdx=*max_element(nextSetBitPos.begin(),nextSetBitPos.end());
            if (maxIdx==-1) ans.push_back(1); //BaseCase
            else ans.push_back(maxIdx-i+1);
        }
        //reverse
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};