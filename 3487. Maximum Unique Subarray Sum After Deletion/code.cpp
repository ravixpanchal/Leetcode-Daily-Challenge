class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans=0;
        set<int>s;
        int maxElement=INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            maxElement=max(maxElement,nums[i]);
            if(nums[i]>0){
                s.insert(nums[i]);
            }
        }
        if(maxElement<=0){
            return maxElement;
        }

        for(auto x: s){
            ans+=x;
        }
        return ans;  
    }
};