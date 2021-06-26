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
int binary_search(struct array* arr,int key,int start,int end) // O(log2(n))
{
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
int interpolation_search(struct array* arr,int key,int start,int end)
{
    while(start<=end && key>=arr->A[start] && key<=arr->A[end])
    {
        int pos = start + (key - arr->A[start])*(end-start)/(arr->A[end]-arr->A[start]);
        if(arr->A[pos]==key) return pos;
        else if(key<arr->A[pos]) end = pos-1;
        else if(key>arr->A[pos]) start = pos+1;
    }
    return -1;
}
int exponential_search(struct array* arr,int key)
{
    int i = 1;
    while(i<arr->len && arr->A[i]<=key)
    {
        i=i*2;
    }
    int start = i/2;
    int end = i>=arr->len?arr->len-1:i;
    return binary_search(arr,key,start,end);
}
int ternary_search(struct array* arr,int key,int start,int end)
{
    while(start<=end)
    {
        int mid1 = start + (end-start)/3;
        int mid2 = end - (end-start)/3;

        if(arr->A[mid1]==key) return mid1;
        if(arr->A[mid2]==key) return mid2;

        if(key<arr->A[mid1]) end = mid1-1;
        else if(key>arr->A[mid2]) start = mid2+1;
        else
        {
            start = mid1+1;
            end = mid2-1;
        }
    }
    return -1;
}
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubble_sort(struct array* arr)
{
    int swapped = 1;
    while(swapped==1)
    {
        swapped = 0;
        int i=0;
        while(i<arr->len-1)
        {
            if(arr->A[i]>arr->A[i+1])
            {
                swap(&arr->A[i],&arr->A[i+1]);
                swapped = 1;
            }
            i++;
        }
    }
}
void insertion_sort(struct array* arr)
{
    for(int i=1;i<arr->len;i++)
    {
        int key = arr->A[i],j=i-1;
        while(j>=0 && arr->A[j]>key)
        {
            arr->A[j+1] = arr->A[j];
            j--;
        }
        arr->A[j+1] = key;
    }
}
void selection_sort(struct array* arr)
{
    for(int i=0;i<arr->len-1;i++)
    {
        int min_ind = i;
        for(int j=i+1;j<arr->len;j++)
        {
            if(arr->A[j]<arr->A[min_ind])
            {
                min_ind = j;
            }
        }
        swap(&arr->A[i],&arr->A[min_ind]);
    }
}
void reverse(struct array* arr)
{
    int i=0,j=arr->len-1;
    while(i<j)
    {
        swap(&arr->A[i],&arr->A[j]);
        i++;
        j--;
    }
}
struct array* set(struct array* arr)
{
    struct array* dup = createArray(arr->len);
    for(int i=0;i<arr->len;i++)
    {
        int flag = 0;
        for(int j=0;j<dup->len;j++)
        {
            if(dup->A[j]==arr->A[i]) 
            {
                flag = 1;
                break;
            }
        }
        if(flag==0) append(dup,arr->A[i]);
    }
    return dup;
}
void set_1(struct array* arr)
{
    int k=0;
    for(int i=0;i<arr->len;i++)
    {
        int flag = 0;
        for(int j=0;j<i;j++)
        {
            if(arr->A[j]==arr->A[i]) 
            {
                flag = 1;
                break;
            }
        }
        if(flag==0) update(arr,k++,arr->A[i]);
    }
    arr->len = k;
}
struct array* set_2(struct array* arr)
{
    struct array* dup = createArray(arr->len);
    bubble_sort(arr);
    append(dup,arr->A[0]);
    for(int i=1;i<arr->len;i++)
    {
        if(arr->A[i]!=arr->A[i-1]) append(dup,arr->A[i]);
    }
    return dup;
}
void set_3(struct array* arr)
{
    bubble_sort(arr);
    int k=1;
    for(int i=1;i<arr->len;i++)
    {
        if(arr->A[i]!=arr->A[i-1]) update(arr,k++,arr->A[i]);
    }
    arr->len = k;
}
struct array* intersection(struct array* set1,struct array* set2)
{
    int n = set1->len<set2->len?set1->len:set2->len;
    struct array* set3 = createArray(n);
    for(int i=0;i<set1->len;i++)
    {
        for(int j=0;j<set2->len;j++)
        {
            if(set1->A[i]==set2->A[j])
            {
                append(set3,set1->A[i]);
                break;
            }
        }
    }
    return set3;
}
struct array* union_set(struct array* set1,struct array* set2)
{
    int n = set1->len + set2->len;
    struct array* set3 = createArray(n);
    for(int i=0;i<set1->len;i++)
    {
        append(set3,set1->A[i]);
    }
    for(int j=0;j<set2->len;j++)
    {
        append(set3,set2->A[j]);
    }
    set_3(set3);
    return set3;
}
struct array* set_difference(struct array* set1,struct array* set2)
{
    int n = set1->len<set2->len?set1->len:set2->len;
    struct array* set3 = createArray(n);
    for(int i=0;i<set1->len;i++)
    {
        int flag = 0;
        for(int j=0;j<set2->len;j++)
        {
            if(set1->A[i]==set2->A[j])
            {
                flag=1;
                break;
            }
        }
        if(flag==0) append(set3,set1->A[i]);
    }
    return set3;
}
struct array* merge(struct array* arr1,struct array* arr2)
{
    int i=0,j=0,n = arr1->len+arr2->len;
    struct array* arr3 = createArray(n);
    while(i<arr1->len && j<arr2->len)
    {
        if(arr1->A[i]<=arr2->A[j])
        {
            append(arr3,arr1->A[i]);
            i++;
        }
        else
        {
            append(arr3,arr2->A[j]);
            j++;
        }
    }
    while(i<arr1->len)
    {
        append(arr3,arr1->A[i]);
        i++;
    }
    while(j<arr2->len)
    {
        append(arr3,arr2->A[j]);
        j++;
    }
    return arr3;
}