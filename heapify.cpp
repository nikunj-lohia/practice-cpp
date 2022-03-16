// C++ program for implement deletion in Heaps 

#include <iostream> 

using namespace std; 

// To heapify a subtree rooted with node i which is 
// an index in arr[]. N is size of heap 
void heapify_iterative(int a[],int n)
{   for(int i=n-1;i>=0;i--)
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
}
void heapify(int arr[], int n, int i) 
{ 
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] > arr[largest]) 
		largest = l; 

	// If right child is larger than largest so far 
	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	// If largest is not root 
	if (largest != i) { 
		swap(arr[i], arr[largest]); 

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest); 
	} 
} 

// Function to delete the root from Heap 
void deleteRoot(int arr[], int& n) 
{ 
	// Get the last element 
	int lastElement = arr[n - 1]; 

	// Replace root with first element 
	arr[0] = lastElement; 

	// Decrease size of heap by 1 
	n = n - 1; 

	// heapify the root node 
	heapify(arr, n, 0); 
} 

/* A utility function to print array of size n */
void printArray(int arr[], int n) 
{ 
	for (int i = 0; i < n; ++i) 
		cout << arr[i] << " "; 
	cout << "\n"; 
} 

// Driver Code 
int main() 
{ 
	 int arr[] = { 10, 5, 3, 2, 4 }; 
  
    int n = sizeof(arr) / sizeof(arr[0]); 
     cout<<n;
    deleteRoot(arr, n); 
  cout<<endl<<n;
    printArray(arr, n); 
  
    return 0; 
} 
