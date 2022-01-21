function fib(n, memo = [])
{
	if(n in memo) return memo[n];
	if(n == 0) return 0;
	if(n == 1) return 1; 
	// memo[n-2] = BigInt(fib((n-2), memo));
	memo[n-1] = BigInt(fib((n-1), memo));
	return (memo[n-1] + BigInt(fib((n-2), memo)));
}

console.log(fib(300));