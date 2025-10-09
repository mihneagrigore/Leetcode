bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int count = 0;

    if(flowerbedSize == 1)
    {
        if(flowerbed[0] == 0 && (n == 1 || n == 0))
            return true;
    }    

    if(flowerbed[0] == 0 && flowerbed[1] == 0)
    {
        count++;
        flowerbed[0] = 1;
    }

    if(flowerbedSize == 1)
    {
        if(count == n)
            return true;
        return false;
    }

    for(int i = 1; i < flowerbedSize - 1; i++)
    {
        if(flowerbed[i] == 0 && flowerbed[i+1] == 0 && flowerbed[i - 1] == 0)
        {
            flowerbed[i] = 1;
            count++;
            i++;
        }
    }

    if(flowerbed[flowerbedSize - 2] == 0 && flowerbed[flowerbedSize - 1] == 0)
        count++;

    if(count >= n)
        return true;
    return false;
}