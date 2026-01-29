#include <stdio.h>
#include <limits.h>

int main() {
    int n, i, j, u, v;
    scanf("%d", &n);

    int cost[n][n], selected[n];
    int edges = 0, min, x = 0, y = 0;
    int totalCost = 0;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &cost[i][j]);
        }
        selected[i] = 0;
    }

    selected[0] = 1;

    while(edges < n-1){
        min = INT_MAX;
        for(i=0;i<n;i++){
            if(selected[i]){
                for(j=0;j<n;j++){
                    if(!selected[j] && cost[i][j]){
                        if(min > cost[i][j]){
                            min = cost[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, cost[x][y]);
        totalCost += cost[x][y];
        selected[y] = 1;
        edges++;
    }

    printf("Total cost = %d", totalCost);
    return 0;
}
