void mergeSort(int *vector, int initialPos, int finalPos) {
    int i, j, k, meio, *vectorTemp;

    if(initialPos == finalPos) return;

    meio = (initialPos + finalPos ) / 2;
    mergeSort(vector, initialPos, meio);
    mergeSort(vector, meio + 1, finalPos);

    i = initialPos;
    j = meio + 1;
    k = 0;
    vectorTemp = (int *) malloc(sizeof(int) * (finalPos - initialPos + 1));

    while(i < meio + 1 || j  < finalPos + 1) {
        if (i == meio + 1 ) {
            vectorTemp[k] = vector[j];
            j++;
            k++;
        } else if (j == finalPos + 1) {
            vectorTemp[k] = vector[i];
            i++;
            k++;
        } else if (vector[i] < vector[j]) {
            vectorTemp[k] = vector[i];
            i++;
            k++;
        } else {
            vectorTemp[k] = vector[j];
            j++;
            k++;
        }

    }
    for(i = initialPos; i <= finalPos; i++) {
        vector[i] = vectorTemp[i - initialPos];
    }
    free(vectorTemp);
}