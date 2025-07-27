class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();
        int count=0;

        for(int i=1;i<n-1;i++){
            if(nums[i]==nums[i-1]) continue;

            int left=i-1;
            int right=i+1;

            while(left>=0 && nums[i]==nums[left]) left--;
            while(right<n && nums[i]==nums[right]) right++;

            if(right>=n || left<0) continue;

            if(nums[i]>nums[left] && nums[i]>nums[right]) count++; //form Hill
            else if(nums[i]<nums[left] && nums[i]<nums[right]) count++; //form Valley
        }
        return count;
        
    }
};