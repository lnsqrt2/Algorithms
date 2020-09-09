
/**
 * HASH!!!!!对于查找目标元素是否存在，hash是一种非常快的方式。
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int *ret = (int *)malloc(2 * sizeof(int));
	int i,j,tmp;
	int *hash = NULL;
	int hash_len,min,max;
	*returnSize = 2;

	//对于某一个元素nums[i]，如果hash表中没出现过target - nums[i]，
	//则把nums[i]放入hash表，否则直接返回结果。
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
	
	hash_len = max-min+1;
	hash = malloc(sizeof(int)*hash_len);
	
	//initial hash table
	for(i=0;i<hash_len;i++){
		hash[i] = 0;
	}
	for(i=0;i<numsSize;i++){
		hash[nums[i]-min] = 1;
	}


	//同一个元素不能计算两次
	for(i=0;i<numsSize;i++){
		if(hash[target - nums[i]-min]==1) {
			ret[0] = i;
			for(j=0;j<numsSize;j++){
				if(target-nums[i] ==nums[j] && i!=j){
					ret[1] = j;
					break;
				}
			}
		}
	}

	
	if(ret[1]<ret[0]) {
		tmp = ret[0];
		ret[0] = ret[1];
		ret[1] = tmp;
	}
	return ret;
}



