class Solution {
public:
void sortDiagonal(vector<vector<int>>&grid,int startX,int startY,bool increasing){
    vector<int>diagonalElements;
    int x=startX;
    int y=startY;
    int n=grid.size();

    //1. Extract all the diagonal elements;
    while(x<n && y<n){
        diagonalElements.push_back(grid[x][y]);
        x++,y++;
    }

    //step2. Sort the elements
    if(increasing){
        sort( diagonalElements.begin(), diagonalElements.end());
    }else{
        sort( diagonalElements.begin(), diagonalElements.end(),greater<int>());
    }

    //step3: put the sorted elements back into the frid
    x=startX,y=startY;
    for(int val:  diagonalElements){
        grid[x][y]=val;
        x++,y++;
    }
}
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();

//Process elements top most
        for(int i=0;i<n;i++){
            sortDiagonal(grid,i,0,false);
        }

        for(int j=1;j<n;j++){
            sortDiagonal(grid,0,j,true);
        }

        return grid;
        
    }
};