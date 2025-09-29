class Solution {
public:
// int digit(int n){


// }
    int addDigits(int num) {
      return num==0 ? 0: 1+(num-1)%9; 
    }
};