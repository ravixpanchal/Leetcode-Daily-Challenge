class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement=INT_MIN;

        for(int i=0;i<nums.size();i++){
            maxElement=max(maxElement,nums[i]);
        }
        int currLen=0;
        int maxLen=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxElement){
                currLen++;
            maxLen=max(currLen,maxLen);
            }else{
                currLen=0;
            }
           
        }
        return maxLen;
        
    }
};