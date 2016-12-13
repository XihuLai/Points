#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define INTVAL 1

typedef int T;

void percDown(T *a, int i, int n);
void swap(T& a, T& b);
void output(T *a, int n);
void heapSort(T *a, int n);
void insertionSort(T* x, int left, int right);
void quickSort(T* a, int left, int right);

void heapSort(T *a, int n)
{
    for( int i = n / 2; i >= 0; i--)
    {
        percDown(a, i, n);
    }

    //printf("\n ==after build heap==\n");
    //output(a, n);

    for( int j = n - 1; j > 0; j-- )
    {
        swap(a[0], a[j]);
        percDown(a, 0, j);
    }
}

void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

bool compare(T a, T b)
{
    // '<' decreasing sort
    // '>' increasing sort
    return b > a;
}

void percDown(T *a, int i, int n)
{
    int child; 
    T tmp;
    //printf("i = %d, n = %d\n", i, n);
    for( tmp = a[i]; (2*i + 1) < n; i = child)
    {
        child = 2*i + 1;
        if( child != n -1 && compare(a[child], a[child+1]) ) {
            child++;
        } 

        if(compare(tmp, a[child]))
            a[i] = a[child];
        else
            break;
    }

    a[i] = tmp;
}

void output(T *a, int n)
{
    for(int i = 0 ; i < n - 1 ; i++)
        printf(" %d , ", a[i]);

    printf(" %d\n ", a[n-1]);
}

//This function is wrong, a and b are passed by value so original pointer are not interchanged.
void swap2(int *a, int *b)
{
    int *t = a;
    a = b;
    b = t;
}

int main(int argc, char **argv)
{
    
    if (argc < 2)
        exit(0);

    int N = atoi(argv[1]);
    if (N < 1)
        exit(0);

    T a[N]; 
    T b[N];
    T c[N];

    srand(time(NULL));

    for(int i = 0; i < N; ++i)
    {
        a[i] = (double) (rand() % 1000);
        b[i] = c[i] = a[i];
    }
    //a[0] = 32;
    //a[1] = 54;
    //a[2] = 87;
    //a[3] = 65;
    //a[4] = 97;
    //a[5] = 84;

    printf("orginal order , N = %d : \n", N );
    output(a, N);

    printf("\nafter heap sort : \n" );
    clock_t t = clock();
    heapSort(a, N);
    clock_t t2 = clock();
    printf("--time by heap : %lu s\n", (t2 - t) / INTVAL);
    output(a, N);

    int i = 3, j = 4;
    swap2(&i, &j);
    printf("i = %d, j = %d\n", i, j);

    int *p = &i;
    int *q = &j;
    swap2(p, q);
    printf("i = %d, j = %d\n", *p, *q);

    printf("\nafter QUICK sort : \n" );
    t = clock();
    quickSort(b, 0, N-1);
    t2 = clock();
    printf("--time by quick : %lu s\n", (t2 - t) / INTVAL);
    output(b, N);
    
    printf("\nafter INSERT sort : \n" );
    t = clock();
    insertionSort(c, 0, N-1);
    t2 = clock();
    printf("--time by quick : %lu s\n", (t2 - t) / INTVAL);
    output(c, N);

    return 0;
}

//*****Begin of Quick sort*****
T media3(T* a, int left, int right )
{
    int center = (left + right) / 2;
    
    if (compare(a[center], a[left])) {
        swap(a[left], a[center]);
    }
    
    if (compare(a[right], a[left])) {
        swap(a[left], a[right]);
    }
    
    if (compare(a[right], a[center])) {
        swap(a[center], a[right]);
    }
    
    swap(a[center], a[right - 1]);
    return a[right - 1];
}

void quickSort(T* a, int left, int right)
{
    //at least 3 elems for media3, otherwise loop would go out of bound
    if ( (left + 20 <= right) ) {
        T pivot = media3(a, left, right);
        int i = left, j = right - 1;
        
        while (true) {
            
            while (compare(a[++i], pivot)) {}
            while (compare(pivot, a[--j])) {}

            if ( i < j) {
                swap(a[i], a[j]);
            } else {
                break;
            }
        }
            
        swap(a[i], a[right - 1]);
        
        quickSort(a, left, i - 1);
        quickSort(a, i + 1, right);
    }
    else
        insertionSort(a, left, right);
}
//*****End of Quick sort*****

void insertionSort(T* x, int left, int right)
{
    T tempItem;
    
    int length = right + 1;
    int i, j;
    
    for(i=left + 1; i<length; i++)
    {
        tempItem = x[i];
        j = i-1;
        
        while(j>=left && compare(tempItem, x[j]))
        {
            x[j+1] = x[j];
            j = j-1;
        }
        x[j+1] = tempItem;
    }
}


