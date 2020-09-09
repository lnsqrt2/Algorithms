/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
	int i = 1;
	int notall9 = 0;
	int *ret = (int *)malloc((digitsSize+1) * sizeof(int));
	while(digitsSize - i >=0) {
		if(digits[digitsSize - i] == 9) {
			digits[digitsSize - i] = 0;
			i++;
		} else {
			notall9 = 1;
			break;
		}
	}
	if(notall9 == 0 ) {
		* returnSize = digitsSize+1;
		ret[0] = 1;
		for(i=1;i<digitsSize+1;i++) {
			ret[i] = 0;
		}
		return ret;
	} else {
		* returnSize = digitsSize;
		digits[digitsSize-i] ++;
		return digits;
	}
}