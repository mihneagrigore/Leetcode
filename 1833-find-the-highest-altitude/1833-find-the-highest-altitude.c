int largestAltitude(int* gain, int gainSize) {
    int max = 0;
    int point = 0;

    for(int i = 0; i < gainSize; ++i) {
        point += gain[i];
        if(max < point)
            max = point;
    }

    return max;
}
