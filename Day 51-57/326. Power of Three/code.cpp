class Solution {
public:
    bool isPowerOfThree(int n) {
        for(int i=0;i<=30;i++){
            long long ans=pow(3,i);
           
            if(n==0) return false;

            if(ans==n){
                return true;
            }
        }
        return false;
        
    }
};