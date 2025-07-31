    class Solution {
    public:
        int subarrayBitwiseORs(vector<int>& arr) {
            set<int>ans;
            set<int>prevOr;

            for(auto x: arr){
                set<int>currOr;
                currOr.insert(x);
                for(auto y: prevOr){
                    currOr.insert(y|x);
                }
                ans.insert(currOr.begin(),currOr.end());
                prevOr=currOr;
            }
            return ans.size();

        }
    };