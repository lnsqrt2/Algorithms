int singleNumber(int* nums, int numsSize){
	int i;
	int ret = 0;
	for(i = 0; i<numsSize ; i++) {
		ret = ret ^ nums[i];
	}
	printf("%d",ret);
	return ret;
}


