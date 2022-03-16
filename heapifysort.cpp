#include <iostream> 
using namespace std; 
void heapify_iterative(int a[],int n,int i)
{    
    while(1)
    {   
        int l=2*i+1,largest=i;
        int r=2*i+2;
        if(l<n&&a[l]>a[largest])
            largest=l;
        if(r<n&&a[r]>a[largest])
            largest=l;
        if(largest!=i)
        {
            swap(a[largest],a[i]);
            i=largest;
        }
        else
        {
            break;
        }            
    }
}
void heapify(int arr[], int n, int i) 
{ 
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 

	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	if (r < n && arr[r] > arr[largest]) 
		largest = r; 
	if (largest != i) { 
		swap(arr[i], arr[largest]); 

		heapify(arr, n, largest); 
	} 
} 
void deleteRoot(int arr[], int n) 
{ 
	
	int lastElement = arr[n - 1]; 
    arr[n-1]=arr[0];
	arr[0] = lastElement; 
	n = n - 1; 
	heapify(arr, n, 0); 
}
void printArray(int arr[], int n) 
{ 
	for (int i = 0; i < n; ++i) 
		cout << arr[i] << " "; 
	cout << "\n"; 
} 
int main()
{
    int a[10]={1,10,2,8,3,7,6,4,5,9};
    for(int i=9;i>=0;i--)
    {
        heapify_iterative(a,10,i);
    }
    printArray(a,10);
    // for(int i=10;i>0;i--)
    // {
    //     deleteRoot(a,i);
    // }
    // printArray(a,10);
}