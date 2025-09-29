class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
      int n=nums.size();

      //sort
      sort(nums.begin(),nums.end(),greater<int>());

      for(int i=0;i<n-2;i++){
        int a=nums[i];
        int b=nums[i+1];
        int c=nums[i+2];

        if(b+c>a){
        return a+b+c;
        }
      }
      return 0;
        
    }
};