class Solution {
    // 0 -> not visited
    // 1 -> pacific
    // 2 -> atlantic
    // 3 -> both
public:
    vector<vector<pair<int,int>>> grid;
    int n, m;

    void dfsAtlantic(int i,int j){
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j].second==2 || grid[i][j].second==3)
            return;
        grid[i][j].second += 2;
        if(j+1<m && grid[i][j].first<=grid[i][j+1].first)
            dfsAtlantic(i,j+1);
        if(j-1>=0 && grid[i][j].first<=grid[i][j-1].first)
            dfsAtlantic(i,j-1);
        if(i+1<n && grid[i][j].first<=grid[i+1][j].first)
            dfsAtlantic(i+1,j);
        if(i-1>=0 && grid[i][j].first<=grid[i-1][j].first)
            dfsAtlantic(i-1,j);  
    } 
    void dfsPacific(int i,int j){
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j].second==1)
            return;
        grid[i][j].second = 1;
        if(j+1<m && grid[i][j].first<=grid[i][j+1].first)
            dfsPacific(i,j+1);
        if(j-1>=0 && grid[i][j].first<=grid[i][j-1].first)
            dfsPacific(i,j-1);
        if(i+1<n && grid[i][j].first<=grid[i+1][j].first)
            dfsPacific(i+1,j);
        if(i-1>=0 && grid[i][j].first<=grid[i-1][j].first)
            dfsPacific(i-1,j);  
    } 
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        n= h.size();
        m=h[0].size();
        grid = vector<vector<pair<int, int>>>(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i].emplace_back(h[i][j],0);
            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            dfsPacific(0,i);
        }
        for(int i=0;i<n;i++)
            dfsPacific(i,0);

        for(int i=0;i<m;i++){
            dfsAtlantic(n-1,i);
        }
        for(int i=0;i<n;i++)
            dfsAtlantic(i,m-1);


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j].second==3)
                    ans.push_back({i,j});
            }
        }
        return ans;
    } 
};
