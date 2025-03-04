#include <stdio.h>
/*
写在前面，主函数仅调用了冒泡排序做测试，如需使用请自行调用，基本解释可以参考链接
https://blog.csdn.net/mwj327720862/article/details/80498455



*/
void maopao(int a[],int n);// 冒泡排序大小端都有  指针法和数组法
void maopao1(int *p,int n);//
void maopao2(int a[],int n);//
void maopao3(int *p,int n);


//选择排序 
void SelectionSort(int *arr, int size)
{
    int i, j, k, tmp;
    for (i = 0; i < size - 1; i++) {
        k = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[k]) {
                k = j;
            }
        }
        tmp = arr[k];
        arr[k] = arr[i];
        arr[i] = tmp;
    }
}
//插入排序
void InsertionSort(int *arr, int size)    
{    
    int i, j, tmp;    
    for (i = 1; i < size; i++) {    
        if (arr[i] < arr[i-1]) {    
            tmp = arr[i];    
            for (j = i - 1; j >= 0 && arr[j] > tmp; j--) {  
                arr[j+1] = arr[j];    
            }  
            arr[j+1] = tmp;    
        }          
    }    
}    

//希尔排序
void ShellSort(int *arr, int size)  
{  
    int i, j, tmp, increment;  
    for (increment = size/ 2; increment > 0; increment /= 2) {    
        for (i = increment; i < size; i++) {  
            tmp = arr[i];  
            for (j = i - increment; j >= 0 && tmp < arr[j]; j -= increment) {  
                arr[j + increment] = arr[j];  
            }  
            arr[j + increment] = tmp;
        }  
    }  
}  


//归并排序 如果需要使用这个函数请先定义
  #define MAXSIZE 100  
void Merge(int *SR, int *TR, int i, int middle, int rightend) 
{
    int j, k, l;  
    for (k = i, j = middle + 1; i <= middle && j <= rightend; k++) {  
        if (SR[i] < SR[j]) {
            TR[k] = SR[i++];
        } else { 
            TR[k] = SR[j++];
        }  
    }  
    if (i <= middle) {
        for (l = 0; l <= middle - i; l++) {
            TR[k + l] = SR[i + l];
        }  
    }  
    if (j <= rightend) {
        for (l = 0; l <= rightend - j; l++) {
            TR[k + l] = SR[j + l];  
        }
    }  
}  
  
void MergeSort(int *SR, int *TR1, int s, int t) 
{  
    int middle;  
    int TR2[MAXSIZE + 1];  
    if (s == t) {
        TR1[s] = SR[s]; 
    } else {  
        middle = (s + t) / 2;
        MergeSort(SR, TR2, s, middle);
        MergeSort(SR, TR2, middle + 1, t);
        Merge(TR2, TR1, s, middle, t);
    }  
}  

//快速排序
void QuickSort(int *arr, int maxlen, int begin, int end)  
{  
    int i, j;  
    if (begin < end) {  
        i = begin + 1;  
        j = end;        
        while (i < j) {  
            if(arr[i] > arr[begin]) {  
                swap(&arr[i], &arr[j]); 
                j--;  
            } else {  
                i++; 
            }  
        }  
        if (arr[i] >= arr[begin]) {  
            i--;  
        }  
        swap1(&arr[begin], &arr[i]);      
        QuickSort(arr, maxlen, begin, i);  
        QuickSort(arr, maxlen, j, end);  
    }  
}  
 
void swap1(int *a, int *b)    
{  
    int temp;  
    temp = *a;  
    *a = *b;  
    *b = temp;  
}  

//桶排序
void bucketSort(int *arr, int size, int max)
{
    int i,j;
    int buckets[max];
    memset(buckets, 0, max * sizeof(int));
    for (i = 0; i < size; i++) {
        buckets[arr[i]]++; 
    }
    for (i = 0, j = 0; i < max; i++) {
        while((buckets[i]--) >0)
            arr[j++] = i;
    }
}

int main()
{
int a[5]={16,12,13,14,15};
int i=0;
maopao(a,5);
maopao1(a,5);
maopao2(a,5);
maopao3(a,5);
    return 0;
}
void maopao(int a[],int n)//
{
	int i,j,t;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(a[j]>a[j+1])
			{
				t=a[j];a[j]=a[j+1];a[j+1]=t;
			}
    for(i=0;i<n;i++)
		printf(" %d ",a[i]);
	printf("\n");
}

void maopao1(int *p,int n)//
{
	int i,j,k,*p1;
	p1=p;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(*(p+j)>*(p+j+1))
			{
				k=*(p+j);*(p+j)=*(p+j+1)=k;
			}
    for(i=0;i<n;i++)
		printf(" %d ",*(p1+i));
	printf("\n");
}
void maopao2(int a[],int n)
{
    int i,j,t;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(a[j]<a[j+1])
			{
				t=a[j];a[j]=a[j+1];a[j+1]=t;
			}
    for(i=0;i<n;i++)
		printf(" %d ",a[i]);
	printf("\n");
}
void maopao3(int *p,int n)//
{
	int i,j,k,*p1;
	p1=p;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(*(p+j)<*(p+j+1))
			{
				k=*(p+j);*(p+j)=*(p+j+1)=k;
			}
    for(i=0;i<n;i++)
		printf(" %d ",*(p1+i));
	printf("\n");
}
