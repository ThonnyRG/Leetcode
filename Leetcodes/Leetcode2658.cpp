int dfs(int i, int j, vector<vector<int>>& grid){
    int fish=grid[i][j];
    grid[i][j]=0;
    for (int a=0; a<4; a++){
        int r=i+d[a],  c=j+d[a+1]; 
        if (r<0 || r>=n || c<0 || c>=m || grid[r][c]==0)
            continue; 
        fish+=dfs(r, c, grid);
    }
    return fish;
}