class Solution {
public:
    string triangleType(vector<int>& nums) {
      int n=nums.size();

      int a=nums[0];
      int b=nums[1];
      int c=nums[2];

      if(a+b<=c || b+c<=a || a+c<=b) return "none";

      if(a==b && b==c) return "equilateral";
      else if (a==b || b==c || c==a) return "isosceles";
      else return "scalene";

   
        
    }
};