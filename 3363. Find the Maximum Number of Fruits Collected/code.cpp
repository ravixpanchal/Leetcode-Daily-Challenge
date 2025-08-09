class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i<j && j<n-1-i){
                    fruits[i][j]=0; //unused
                }
                if(j<i && i<n-1-j){
                    fruits[i][j]=0;
                }
            }
        }
        int ans1=0;
        for(int i=0;i<n;i++){
            ans1+=fruits[i][i];
        }

        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                fruits[i][j]+=max(fruits[i-1][j-1],max(fruits[i-1][j],(j+1<n)?fruits[i-1][j+1]:0));
            }
        }

        for(int j=1;j<n;j++){
            for(int i=j+1;i<n;i++){
                fruits[i][j]+=max(fruits[i-1][j-1],max(fruits[i][j-1],(i+1<n)?fruits[i+1][j-1]:0));
            }
            }
        return ans1+fruits[n-1][n-2]+fruits[n-2][n-1];
    }
};