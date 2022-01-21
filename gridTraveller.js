const gridTraveller = (m, n, memo = {}) => 
{
	let key = m + ',' + n;
	let keyreverse = n + ',' + m;      //time: O(n * m)
	if(key in memo) return memo[key];  //space: O(n + m)
	if(keyreverse in memo) return memo[keyreverse];
	if(m == 0 || n == 0) return 0;
	if(m == 1 && n == 1) return 1;
	memo[key] = gridTraveller(m-1, n, memo) + gridTraveller(m, n-1, memo);
	return memo[key];
}

console.log(gridTraveller(18,18));

