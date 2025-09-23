class Solution {
public:

    bool find(vector<vector<char>>& board,int i,int j,int index,string &word){
        int n=board.size();
        int m=board[0].size();
        if(index==word.size()) return true;

        if(i<0 || j<0 ||i>=n || j>=m || board[i][j] =='$') return false;

        if(board[i][j]==word[index]){
            char temp=board[i][j];
            board[i][j]='$';

            bool res=find(board,i+1,j,index+1,word) ||
                     find(board,i-1,j,index+1,word) ||
                     find(board,i,j-1,index+1,word) ||
                     find(board,i,j+1,index+1,word);
            
            board[i][j]=temp;
            return res;


        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && find(board,i,j,0,word)){
                    return true;
                }
            }
        }
        return false;
        
    }
};