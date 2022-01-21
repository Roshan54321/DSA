//this program is for checking if the number can be obtained by summing the required elements in the given array
const canSum = (n, array, memo = []) => {
	if(n in memo) return memo[n];
	if(n === 0) return true;
	if(n < 0) return false;            //time: O(n * m)
									   space: O(m)
	for(let num of array)
	{
		if(canSum(n-num, array, memo)){
			return memo[n] = true;
		} 
	}
	return memo[n] = false;
};

console.log(canSum(7, [7, 5, 3, 4]));


//this program is for obtaining the array of numbers falling in the given array that sum to give the given number
const sumArray = (n, array, memo = [])=> {
	if(n in memo) return memo[n];
	if(n === 0) return a;
	if(n < 0) return null;
	for(let num of array)    //time: O(n * m ^ 2)
	{						 //space: O(m)
		a.push(num);
		if(canSum(n-num, array, memo)){
			return memo[n] = a;
		} 
		a.pop();
	}
	return memo[n] = null;
};

let a = [];
console.log(sumArray(0, [7, 14]));