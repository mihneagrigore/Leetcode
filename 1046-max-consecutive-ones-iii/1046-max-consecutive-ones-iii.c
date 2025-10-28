int longestOnes(int* nums, int numsSize, int k) {
    int left = 0;
    int right;
    int zeros = 0;
    int max_len = 0;

    for (right = 0; right < numsSize; right++) {
        if (nums[right] == 0)
            zeros++;

        while (zeros > k) {
            if (nums[left] == 0)
                zeros--;
            left++;
        }

        int current_len = right - left + 1;
        if (current_len > max_len)
            max_len = current_len;
    }

    return max_len;
}
