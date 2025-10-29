void moveZeroes(int* nums, int numsSize) {
    int lastNonZero = 0; 

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            if (i != lastNonZero) {
                int temp = nums[i];
                nums[i] = nums[lastNonZero];
                nums[lastNonZero] = temp;
            }
            lastNonZero++;
        }
    }
}
