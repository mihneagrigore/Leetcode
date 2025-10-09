/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {

    bool *result = malloc(sizeof(bool) * candiesSize);
    *returnSize = candiesSize;
    for(int i = 0; i < candiesSize; i++)
    {
        bool ok = true;
        for(int j = 0; j < candiesSize; j++)
        {
            if(candies[j] > candies[i] + extraCandies)
            {
                result[i] = false;
                ok = false;
                break;
            }
        }
        if(ok)
            result[i] = true;
    }

    return result;
    
}