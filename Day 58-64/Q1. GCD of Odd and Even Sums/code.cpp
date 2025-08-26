class Solution {
public:
    int evenSum(int n){
          int sum=0;
        for(int i=1;i<=n;i++){
            sum+=i*2;
        }
        return sum;
    }

       int oddSum(int n){
            int sum=0;
        for(int i=1;i<=n;i++){
            sum+=i*2-1;
        }
           return sum;
    }

    int gcd(int a,int b){
        if(a>0 && b>0){
            if(a>b){
                a=a%b;
            }else{
                b=b%a;
            }
        }

        if(a==0) return b;
        return a;
        
    }
    int gcdOfOddEvenSums(int n) {
        int a=evenSum(n);
        int b=oddSum(n);
        return gcd(a,b);
        
    }
};