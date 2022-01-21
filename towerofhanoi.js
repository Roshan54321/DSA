function TOH(N, S, A, D)
{
	if(N == 1)
	{
	console.log(`${S} to ${D}`);
	return;
	} 
	else{
	TOH(N-1, S, D, A);
	TOH(1, S, A, D);
	TOH(N-1, A, S, D);
	}
}

TOH(3, 1, 2, 3);