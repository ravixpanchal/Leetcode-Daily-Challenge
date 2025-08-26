class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int top=INT_MAX;
        int bottom=-1;
        int left=INT_MAX;
        int right=-1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                left=min(left,j);
                right=max(right,j);
                top=min(i,top);
                bottom=max(i,bottom);
                }
            }
        }
        return (bottom-top+1)*(right-left+1);
        
    }
};