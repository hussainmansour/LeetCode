class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid, char c){
        if(i >= grid.size() || i < 0 || j >= grid[i].size() || j < 0 || grid[i][j]==c || grid[i][j]=='0')
            return;
        grid[i][j] = c;
        dfs(i-1,j,grid,c);//left
        dfs(i+1,j,grid,c);//right
        dfs(i,j-1,grid,c);//up
        dfs(i,j+1,grid,c);//down
    }

    int numIslands(vector<vector<char>>& grid) {
        char c = '2';
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if(grid[i][j]=='1') {
                    ans++;
                    dfs(i, j, grid, c);
                }
            }
        }
        return ans;
    }
};
