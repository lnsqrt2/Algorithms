void reverseArray(int* nums, int begin, int end)
{
	int i,j;
	int temp;
	for(i=begin,j=end; i<=(begin+end)/2 ;i++){	//{1,2,3,4,5,6}
		temp = nums[i];							// 0 1 2 3 4 5 
		nums[i] = nums[j];
		nums[j] = temp;
		j--;
	}
}



void rotate(int* nums, int numsSize, int k){
	int i =0;
	int tmp,count;
	
	k%=numsSize;

	if(k == 0)
		return NULL;
	
	reverseArray(nums,numsSize-k,numsSize-1);
	reverseArray(nums,0,numsSize-1-k);
	reverseArray(nums,0,numsSize-1);
	


	printf("[%d",nums[0]);
	for(i = 1; i<numsSize; i++){
		printf(",%d",nums[i]);
	}
	printf("]\n");

}