class Solution {
public:
vector<int>generateRow(int numRows){
    long long ans=1;
    vector<int>ansRow;
    ansRow.push_back(ans);

    for(int col=1;col<numRows;col++){
        ans=ans*(numRows-col);
        ans=ans/col;
        ansRow.push_back(ans);
    }
    return ansRow;

}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRow(i));
        }
       return ans;
        
    }
};