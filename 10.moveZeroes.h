void moveZeroes(int* nums, int numsSize){
	//int *zp = (int *)malloc(numsSize * sizeof(int));
	int i;
	int current = 0;
	int zeronum = 0;



	for(i=0;i<numsSize;i++) {
		if(nums[i] != 0) {
			nums[current] = nums[i];
			current++;
		} else {
			zeronum++;
		}
	}

	for(i=1;i<=zeronum;i++) {
		nums[numsSize-i] = 0;
	}
}
