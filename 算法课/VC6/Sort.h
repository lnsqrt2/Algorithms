//n elements, n = right-left+1
//BubbleSort(nums, 0, numsSize-1)
void BubbleSort(int *data, int left, int right) {
	int tmp = 0;
	int exchange_flag = 0;
	int i,j;
	for(i = 1; i <= right-left; i++){	//bubble n-1 times, find min in a time
		exchange_flag = 0;
		for(j=right ; j>=left+i ;j--) {		//from data[left+i] to end
			if(data[j-1]>data[j]) {			//compare with front element
				tmp = data[j-1];
				data[j-1] = data[j];
				data[j] = tmp;
				exchange_flag = 1;
			}
		}
		if(exchange_flag == 0)				//in one time, no swap means sorted
			return;
	}
	return;
}
 