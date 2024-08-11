class Solution {

    static int dir[][] = {{0,1},{0,-1},{-1,0},{1,0}};
    static int n;
    static int m;

    static void bfs(int arr[][],int r, int c){
        int visited[][] = new int[n][m];
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{r,c});
        visited[r][c] = 1;

        while(q.size()!=0){
            int a[] = q.remove();
            for(int k=0; k<4; k++){
                int nr = a[0]+dir[k][0];
                int nc = a[1]+dir[k][1];
                if(nr>=0 && nc>=0 && nr<n && nc<m && arr[nr][nc]==1 && visited[nr][nc]==0){
                    visited[nr][nc] = 1;
                    arr[nr][nc] = 0;
                    q.add(new int[]{nr,nc});
                }
            }
        }
    }
    public int minDays(int[][] grid) {
        n = grid.length;
        m = grid[0].length;

        
        ArrayList<int[]> point = new ArrayList<>();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    point.add(new int[]{i,j});
                }
            }
        }
        int arr[][] = new int[n][m];
        for(int i=0; i<n; i++) arr[i] = Arrays.copyOf(grid[i],grid[i].length);

        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]==1){
                    bfs(arr,i,j);
                    ans++;
                }
            }
        }
        if(ans>1 || ans==0) return 0;

        

        for(int p=0; p<point.size(); p++){    
            int r = point.get(p)[0];
            int c = point.get(p)[1];
            arr = new int[n][m];
            for(int k=0; k<n; k++) arr[k] = Arrays.copyOf(grid[k],grid[k].length);
            arr[r][c] = 0;
            ans = 0;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(arr[i][j]==1){
                        bfs(arr,i,j);
                        ans++;
                    }
                }
            }
            if(ans>1 || ans==0) return 1;
        }
        return 2;
    }
}