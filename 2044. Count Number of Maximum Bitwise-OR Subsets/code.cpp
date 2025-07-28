class Solution {
public:
    int maxOr=0;
    int calc(vector<int>&nums,int idx,int curr){
        int n=nums.size();

        //BaseCase

        if(idx==n){
            if(curr==maxOr) return 1;
            return 0;
        }

        int include=calc(nums,idx+1,curr|nums[idx]);
        int exclude=calc(nums,idx+1,curr);

        return include+exclude;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int max=0;

        for(auto i: nums) max|=i;
        maxOr=max;

        return calc(nums,0,0); //store array,index,curr

        
    }
};