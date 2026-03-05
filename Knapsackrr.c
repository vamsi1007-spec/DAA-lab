#include <stdio.h>

int main() {
    int n,i,j;
    float w[20],v[20],r[20],c,temp,max=0;

    printf("Enter number of items: ");
    scanf("%d",&n);

    printf("Enter weight and value of each item:\n");
    for(i=0;i<n;i++)
        scanf("%f %f",&w[i],&v[i]);

    printf("Enter knapsack capacity: ");
    scanf("%f",&c);

    for(i=0;i<n;i++)
        r[i]=v[i]/w[i];

    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(r[i]<r[j]){
                temp=r[i]; r[i]=r[j]; r[j]=temp;
                temp=w[i]; w[i]=w[j]; w[j]=temp;
                temp=v[i]; v[i]=v[j]; v[j]=temp;
            }

    for(i=0;i<n;i++){
        if(c>=w[i]){
            max+=v[i];
            c-=w[i];
        }
        else{
            max+=r[i]*c;
            break;
        }
    }

    printf("Maximum value = %.2f\n",max);

    return 0;
}