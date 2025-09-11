class Solution {
public:
#define ll long long
    int makeTheIntegerZero(int num1, int num2) {
        for(ll k=1;k<=60;k++){
            ll target=num1-k*num2;

            if(target<k) break;

            ll setbits=__builtin_popcountll(target);
            if(setbits<=k) return (int)k;
            

        }
        return -1;
        
    }
};