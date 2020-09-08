/**
 * @param {number} n
 * @return {number}
 */
var numSquares = function(n) {      
  let dp = Array(n + 1).fill(n)
    
    dp[n] = 0
    
    let q = [n]
    while(q.length != 0){
      now = q.shift()
      
      let sqrtn = parseInt(Math.sqrt(now) + "")
      for(i = sqrtn; i > 0; i--) {
        let next = now - i*i
          
        if(next >= 0 && dp[next] > dp[now] + 1){
          q.push(next)
          
          dp[next] = dp[now] + 1
        }
      }
    }
    
  return dp[0] 
};

console.log(numSquares(101111))
