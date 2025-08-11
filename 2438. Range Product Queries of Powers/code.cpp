class Solution {
public:
int mod=1000000007;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int res=1;
        vector<int>powers;
        while(n){
            if(n%2==1){
                powers.push_back(res);
            }
            res*=2;
            n/=2;
        }

        vector<int>result;
        for(auto &query:queries ){
            int currResult=1;
            for(int i=query[0];i<=query[1];i++){
                currResult=(long long)(currResult)*powers[i]%mod;
            }
            result.push_back(currResult);
        }
        return result;

    }
};