int reverse(int x){
	long ret = 0;
	while(x!=0){
		ret = ret*10 + x%10;
		x=(x/10);
	}
	if(ret>2147483648 || ret <-2147483648)
		return 0;
	return (int)ret;
}