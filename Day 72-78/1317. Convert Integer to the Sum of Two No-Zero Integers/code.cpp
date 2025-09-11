class Solution {
public:
bool isNotZero(int x){
    while(x>0){
    if(x%10==0) return false;
    x=x/10;
    }
    return true;
}
    vector<int> getNoZeroIntegers(int n) {
        vector<int>ans;

        for(int i=1;i<n;i++){
            int a=i;
            int b=n-i;

            if(isNotZero(a) && isNotZero(b)){
              ans.push_back(a);
              ans.push_back(b);
              break;
            }
        }
        return ans;
        
    }
};