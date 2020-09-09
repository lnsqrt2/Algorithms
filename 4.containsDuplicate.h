bool containsDuplicate(int* nums, int numsSize)
{
	//HASH
	
	//1. find min and max element
	//2. 存入哈希表，直接映射，min代表第一个元素，max为最后一个元素

	int i;
	int min,max,len;


	if(numsSize <= 1){
		return false;
	}

	min = nums[0];
	max = nums[0];
	for(i = 0; i<numsSize; i++){
		if(nums[i] > max){
			max = nums[i];
		}
		if(nums[i] < min){
			min = nums[i];
		}
	}
	
	int hash_len = max-min+1;
	int* hash = malloc(sizeof(int)*hash_len);

	//3.initial hash table
	for(i=0;i<hash_len;i++){
		hash[i] = 0;
	}

	for(i=0;i<numsSize;i++){
		if(hash[nums[i]-min]==1)
			return true;
		hash[nums[i]-min] = 1;
	}
	
	return false;
}

