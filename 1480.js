/**
 * @param {number[]} nums
 * @return {number[]}
 */
var runningSum = function(nums) {
    let ret = []

    let sum = 0
    for(let n of nums){
        ret.push(sum += n)
    }

    return ret
};