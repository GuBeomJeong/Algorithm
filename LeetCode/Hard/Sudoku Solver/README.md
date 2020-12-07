# Sudoku Solver
스도쿠를 푸는 문제이고 별다른 처리 없이 box, row, col에 없는 숫자만 채워넣어보는 방법으로 했다. 

``` C++
class Solution {
public:
    
    int n = 9;
        
    bool box[3][3][10];
    bool row[10][10];
    bool col[10][10];
    
    bool solve(vector<vector<char>>& board,int x,int y){
        
        if(x == n){
            return true;
        }
        
        int nx = x;
        int ny = y + 1;
          
        if(ny == n){
            nx++;
            ny = 0;
        }
        
        if(board[x][y] != '.'){
            return solve(board,nx,ny);
        }
        
        for(int i=1;i<10;i++){
            
            if(!box[x/3][y/3][i] && !row[x][i] && !col[y][i]){
                box[x/3][y/3][i] = row[x][i] = col[y][i] = true;
                board[x][y] = i + '0';
                if(solve(board,nx,ny)){
                    return true;
                }
                box[x/3][y/3][i] = row[x][i] = col[y][i] = false;
                board[x][y] = '.';
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        
        memset(box,false,sizeof(box));
        memset(row,false,sizeof(row));
        memset(col,false,sizeof(col));
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] != '.'){
                    box[i/3][j/3][board[i][j] - '0'] = true;
                    row[i][board[i][j] - '0'] = true;
                    col[j][board[i][j] - '0'] = true;
                }
            }
        }
        
        solve(board,0,0);
        
    }
};
```
ios~~ 로 시작하는 입출력 최적화 제외하고 99% 를 노려야겠다.
> Runtime: 8 ms, faster than 86.41% of C++ online submissions for Sudoku Solver.
Memory Usage: 8.8 MB, less than 93.10% of C++ online submissions for Sudoku Solver.
