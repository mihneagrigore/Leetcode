double findMaxAverage(int* nums, int numsSize, int k) {
    double sum = 0;
    for(int i = 0; i < k; i++)
        sum+=nums[i];
    
    double max_average = sum / k;
    for(int i = 0, j = k - 1; j < numsSize - 1; i++, j++)
    {
        sum -= nums[i];
        sum += nums[j+1];
        
        if(max_average < sum / k)
            max_average = sum / k;
    }

    return max_average;
}