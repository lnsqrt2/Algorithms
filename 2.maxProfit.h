int maxProfit(int* prices, int pricesSize){
	int p1 = 0;
	int p2 = 1;
	int maxPrft = 0;


	for(p2 = 1;p2<pricesSize;p2++){
		if(prices[p2]>prices[p1]){	//buy & sell
			maxPrft = maxPrft+prices[p2]-prices[p1];
			printf("buy price%d, sell price%d\n",prices[p1],prices[p2]);
		}
		p1 = p2;
	}
	return maxPrft;
}