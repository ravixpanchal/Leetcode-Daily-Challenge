class Solution {
public:
#define ll  long long
    long long flowerGame(int n, int m) {
        ll count=0;

        //Case1: n is odd and m is even
        ll n_is_odd=(n+1)/2;
        ll m_is_even=m/2;
        count+=(n_is_odd*m_is_even);

        //Case2: n is even  and m is odd
        ll n_is_even=n/2;
        ll m_is_odd=(m+1)/2;
        count+=(n_is_even)*(m_is_odd);

        return count;
        
    }
};