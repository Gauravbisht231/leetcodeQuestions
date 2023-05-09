/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
   var res=[];
   let n= arr.length;
    for(let i=0; i<n; i++){
    if(fn(arr[i], i)) res.push(arr[i]);
   
    }
    return res;
};
