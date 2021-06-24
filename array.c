#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct array
{
    int *A; // Array in Heap
    int size; // maximum number of elements that could be accomodated in the array
    int len; // present number of elements available in the array
};
struct array* createArray(int n)
{
    struct array* arr = (struct array*)malloc(sizeof(struct array));
    arr->size = n;
    arr->len = 0;
    arr->A = (int*)malloc(sizeof(int)*arr->size);
    return arr;
}
void append(struct array* arr,int data)
{
    if(arr->len < arr->size)
    {
        arr->A[arr->len] = data;
        arr->len++;
    }
    else
    {
        printf("Error: No more Space available in the array\n");
    }
}
int pop(struct array* arr)
{
    if(arr->len>0)
    {
        arr->len--;
        return arr->A[arr->len];
    }
    else
    {
        return -1;
    }
}
void traverse(struct array* arr)
{
    for(int i=0;i<arr->len;i++)
    {
        printf("%d ",arr->A[i]);
    }
    printf("\n");
}
void insert(struct array* arr,int ind,int data)
{
    if(ind>=0 && ind<arr->size)
    {
        for(int i=arr->len-1;i>=ind;i--)
        {
            arr->A[i+1] = arr->A[i];
        }
        arr->A[ind] = data;
        arr->len++;
    }
    else
    {
        printf("Error: Invalid Index");
    }
}
void update(struct array* arr,int ind,int data)
{
    if(ind>=0 && ind<arr->size)
    {
        arr->A[ind] = data;
    }
}
void delete(struct array* arr,int data)
{
    int ind = -1;
    for(int i=0;i<arr->len;i++)
    {
        if(arr->A[i]==data)
        {
            ind = i;
            break;
        }
    }
    if(ind!=-1)
    {
        for(int i=ind+1;i<arr->len;i++)
        {
            arr->A[i-1] = arr->A[i];
        }
        arr->len--;
    }
}
void delete_at(struct array* arr,int ind)
{
    if(ind>=0 && ind<arr->len)
    {
        for(int i=ind+1;i<arr->len;i++)
        {
            arr->A[i-1] = arr->A[i];
        }
        arr->len--;
    }
}
int linear_search(struct array* arr,int key)
{
    for(int i=0;i<arr->len;i++)
    {
        if(arr->A[i]==key) return i; 
    }
    return -1;
}
int binary_search(struct array* arr,int key) // O(log2(n))
{
    int start = 0,end = arr->len-1;
    while(start<=end)
    {
        int mid = (start+end)/2;
        if(key == arr->A[mid]) return mid;
        else if(key<arr->A[mid]) end = mid-1;
        else if(key>arr->A[mid]) start = mid+1;
    }
    return -1;
}
int jump_search(struct array* arr,int key)
{
    int m = sqrt(arr->len),i;
    for(i=0;i<arr->len;i+=m)
    {
        if(arr->A[i]==key) return i;
        else if(arr->A[i]>key) break;
    }
    for(int j=i-m+1;j<=i-1;j++)
    {
        if(arr->A[j]==key) return j;
    }
    return -1;
}
int interpolation_search(struct array* arr,int key)
{
    int start = 0,end = arr->len-1;
    while(start<=end && key>=arr->A[start] && key<=arr->A[end])
    {
        int pos = start + (key - arr->A[start])*(end-start)/(arr->A[end]-arr->A[start]);
        if(arr->A[pos]==key) return pos;
        else if(key<arr->A[pos]) end = pos-1;
        else if(key>arr->A[pos]) start = pos+1;
    }
    return -1;
}
int main()
{
    int n;
    scanf("%d",&n);
    struct array* arr = createArray(n);
    append(arr,10);
    append(arr,20);
    append(arr,30);
    append(arr,40);
    append(arr,50);
    append(arr,60);
    append(arr,70);
    int ind = interpolation_search(arr,50);
    if(ind==-1)
    {
        printf("The element is not found\n");
    }
    else
    {
        printf("The element is found at index %d\n",ind);
    }
    traverse(arr);
}