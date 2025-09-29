class Solution {
public:

    int numSquare(int n){
      int ans=0;
      while(n!=0){
        int digit=n%10;
        ans+=digit*digit;
        n=n/10;
      }
      return ans;
    }

    bool isHappy(int n) {
      set<int>s;

      while(n!=1 && s.find(n)==s.end()){
        s.insert(n);
        n=numSquare(n);
      }
      return n==1;
  
    }
};