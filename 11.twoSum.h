
/**
 * HASH!!!!!���ڲ���Ŀ��Ԫ���Ƿ���ڣ�hash��һ�ַǳ���ķ�ʽ��
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int *ret = (int *)malloc(2 * sizeof(int));
	int i,j,tmp;
	int *hash = NULL;
	int hash_len,min,max;
	*returnSize = 2;

	//����ĳһ��Ԫ��nums[i]�����hash����û���ֹ�target - nums[i]��
	//���nums[i]����hash������ֱ�ӷ��ؽ����
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


	//ͬһ��Ԫ�ز��ܼ�������
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



