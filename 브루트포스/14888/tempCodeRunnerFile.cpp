    for (int i = 0; i < 4; i++) {
        int temp = 1;

        for (int j = 1; j <= arr[i]; j++) {
            temp *= j;
        }
        sum /= temp;
    }