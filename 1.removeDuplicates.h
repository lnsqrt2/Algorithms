
int removeDuplicates(int* nums, int numsSize){
	
	//��һ���������飬ɾ���ظ�Ԫ�أ�Ȼ�󷵻�ɾ�����Ԫ�ظ���
	//�����Ԫ�ز��ùܡ�ֻҪ��֤ǰ���ǲ��ظ��ģ�Ȼ�������ȷ�����鳤�ȼ���
	
	
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