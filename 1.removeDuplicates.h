
int removeDuplicates(int* nums, int numsSize){
	
	//对一个有序数组，删除重复元素，然后返回删除后的元素个数
	//后面的元素不用管。只要保证前面是不重复的，然后给出正确的数组长度即可
	
	
	int p1 = 0;
	int p2 = 1;

	if(numsSize == 0)
		return 0;
	for(p2=1;p2<numsSize;p2++){
		if(nums[p1] != nums[p2])
		{
			nums[p1+1] = nums[p2];
			p1++;
		}
	}
	return p1+1;
}