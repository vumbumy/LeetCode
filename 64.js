let dx = [1, 0]
let dy = [0, 1]

let n, m;

var isRange = function(x, y){
  return x >= 0 && x < m && y >= 0 && y < n  
}

MAX_COST = Math.pow(2, 31) - 1

/**
 * @param {number[][]} grid
 * @return {number}
 */  
var minPathSum = function(grid) {
    n = grid.length
    m = grid[0].length
      
    let q = [[0, 0]]

    let dp = Array.from(Array(n), () => Array(m).fill(MAX_COST))
    dp[0][0] = grid[0][0]
    
    while(q.length != 0){
      now = q.shift()
      
      for(i=0;i<2;i++){
        xx = now[0] + dx[i]
        yy = now[1] + dy[i]        
        
        if(isRange(xx, yy) && dp[yy][xx] > grid[yy][xx] + dp[now[1]][now[0]]){ 
          dp[yy][xx] = grid[yy][xx] + dp[now[1]][now[0]]
          
          q.push([xx, yy])  
        }
      }
    }
    
    return dp[n-1][m-1]
};


let grid = [[1,2,5],[3,2,1]]

console.log(minPathSum(grid))
