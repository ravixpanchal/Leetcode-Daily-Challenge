class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        //We are using the sliding window in this Question!
        int ans=0;
        int sum=0;
        int left=0;
        set<int>s;

        for(int right=0;right<nums.size();right++){
            while(s.find(nums[right])!=s.end()){
                s.erase(nums[left]);
                sum-=nums[left];
                left++;
            }
            s.insert(nums[right]);
            sum+=nums[right];
            ans=max(ans,sum);
        }
        return ans;
        
    }
};