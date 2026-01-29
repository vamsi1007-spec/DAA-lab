#include <stdio.h>

int main() {
    int n, i, j;
    float capacity, totalValue = 0.0, temp;

    scanf("%d", &n);

    float weight[n], value[n], ratio[n];

    for(i=0;i<n;i++)
        scanf("%f %f", &weight[i], &value[i]);

    scanf("%f", &capacity);

    for(i=0;i<n;i++)
        ratio[i] = value[i] / weight[i];

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(ratio[i] < ratio[j]){
                temp = ratio[i]; ratio[i] = ratio[j]; ratio[j] = temp;
                temp = weight[i]; weight[i] = weight[j]; weight[j] = temp;
                temp = value[i]; value[i] = value[j]; value[j] = temp;
            }
        }
    }

    for(i=0;i<n;i++){
        if(capacity >= weight[i]){
            capacity -= weight[i];
            totalValue += value[i];
        } else {
            totalValue += ratio[i] * capacity;
            break;
        }
    }

    printf("Maximum value = %.2f", totalValue);
    return 0;
}
