/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {

    int *result = calloc(sizeof(int), numsSize);
    *returnSize = numsSize;

    int zeros = 0, zero_pos = -1;
    for(int i = 0; i < numsSize; i++)
        if(nums[i] == 0)
        {
            zeros++;
            zero_pos = i;
        }
    if(zeros >= 2)
        return result;

    int prod = 1;
    for(int i = 0; i < numsSize; i++)
        if(nums[i] != 0)
            prod *= nums[i];
    
    if(zeros)
    {
        result[zero_pos] = prod;
        return result;
    }
    
    for(int i = 0; i < numsSize; i++)
        result[i] = prod / nums[i];

    return result;    
}