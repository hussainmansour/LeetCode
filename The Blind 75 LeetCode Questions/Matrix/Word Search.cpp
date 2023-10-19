class Solution {
public:
    bool dfs(int i,int j,int n,int m,vector<vector<char>>& board,string& word,int ind)
    {
        if(i>=n||j>=m)return false;
        if(ind+1==word.size())return true;
        bool op1 = false;
        char t = board[i][j];
        board[i][j]='1';
        if(i+1<n && board[i+1][j] == word[ind+1])
            op1 |= dfs(i+1,j,n,m,board,word,ind+1);
        
        if(i-1>=0 && board[i-1][j] == word[ind+1])
            op1 |= dfs(i-1,j,n,m,board,word,ind+1);
        
        if(j+1<m && board[i][j+1] == word[ind+1])
            op1 |= dfs(i,j+1,n,m,board,word,ind+1);

        if(j-1>=0 && board[i][j-1] == word[ind+1])
            op1 |= dfs(i,j-1,n,m,board,word,ind+1);
        board[i][j]=t;
        return op1;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n,m;
        n = board.size();
        m = board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == word[0])
                {
                    if(dfs(i,j,n,m,board,word,0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
