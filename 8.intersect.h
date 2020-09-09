
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
	int i,j;
	int *ret = NULL;
	*returnSize = 0;
	if(nums1Size < nums2Size) {
		ret = (int *)malloc(nums1Size * sizeof(int));
		for(i = 0;i<nums1Size;i++) {
			for(j = 0;j<nums2Size;j++){
				if(nums1[i] == nums2[j]) {
					ret[*returnSize] = nums1[i];
					(*returnSize)++;
					nums2[j] = 98989898;//É¾³ý±ê¼Ç
					break;
				}
			}
		}
	} else {
		ret = (int *)malloc(nums2Size * sizeof(int));
		for(i = 0;i<nums2Size;i++) {
			for(j = 0;j<nums1Size;j++){
				if(nums2[i] == nums1[j]) {
					ret[*returnSize] = nums2[i];
					(*returnSize)++;
					nums1[j] = 98989898;
					break;
				}
			}
		}
	}
	return ret;
}
