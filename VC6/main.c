#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"

#include "D:\workspace\Algorithm\11.twoSum.h"

int main(void)
{
	int i =0;
	char s[5]	=	{'h','e','l','l','o'};
	int sSize	=	5;
	
	int nums[3] = {3,2,4};
	int numsSize = 3;
	int target = 6;

	int nums1[2] = {1,2};
	int nums1Size = 2;

	int nums2[2] = {1,1};
	int nums2Size = 2;

	int digits[3] = {1,2,3};
	int digitsSize = 3;

	int *ret = NULL;
	int returnSize[1] = {0};

	ret = twoSum(nums,numsSize,target,returnSize);

	
	for(i=0;i<*returnSize;i++){
		printf("%d\n",ret[i]);
	}
	free(ret);

	return 0;
}