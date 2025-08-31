class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        
           //reverse
        for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        }
        
        //adjoint
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
    }
};
