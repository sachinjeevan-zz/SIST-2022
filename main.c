#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "array.h"
int main()
{
    struct array* arr = createArray(10);
    append(arr,10);
    append(arr,20);
    append(arr,30);
    append(arr,40);
    append(arr,50);
    traverse(arr);
}