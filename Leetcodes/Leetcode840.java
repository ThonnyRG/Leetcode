class Solution {

    static int magic(int a, int b, int c, int d, int e,
                     int f, int g, int h, int i)
    {
        HashSet<Integer> s1 = new HashSet<Integer>(
            Arrays.asList(a, b, c, d, e, f, g, h, i));
 
        HashSet<Integer> s2 = new HashSet<Integer>(
            Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9));

        if (s1.equals(s2) && (a + b + c) == 15
            && (d + e + f) == 15 && (g + h + i) == 15
            && (a + d + g) == 15 && (b + e + h) == 15
            && (c + f + i) == 15 && (a + e + i) == 15
            && (c + e + g) == 15)
            return 1;
        return 0;
    }


    public int numMagicSquaresInside(int[][] grid) {
        int answer = 0, Nrows = grid.length, Ncolumns = grid[0].length;
        if(Nrows >= 3 && Ncolumns >= 3){
            for (int i = 0; i < Nrows; i++) {
                for (int j = 0; j < Ncolumns; j++) {
                    if(grid[i + 1][j + 1] != 5) continue;

                    if (magic(grid[i][j], grid[i][j + 1],
                    grid[i][j + 2], grid[i + 1][j],
                    grid[i + 1][j + 1],
                    grid[i + 1][j + 2],
                    grid[i + 2][j],
                    grid[i + 2][j + 1],
                    grid[i + 2][j + 2])
              != 0)

             answer += 1;
                }
            }


        }else{
            answer = 0;
        }
        return answer;
    }
}