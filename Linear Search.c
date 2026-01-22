#include <stdio.h>

int main() {
    int a[] = {5, 3, 8, 2, 9};
    int n = sizeof(a)/sizeof(a[0]);
    int key = 8;
    int i, pos = -1;

    for(i=0;i<n;i++){
        if(a[i] == key){
            pos = i;
            break;
        }
    }

    if(pos != -1) printf("Element found at index %d", pos);
    else printf("Element not found");
    return 0;
}