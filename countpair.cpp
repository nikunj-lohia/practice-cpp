#include<bits/stdc++.h>
using namespace std;
int countPair(int arr[], int size, int a, int b) {
    int cnt = 0;
    int i = 0, low = size-1,high=size-1;
    while (i < high) {
        low = max(i, low);
        while (low > i && arr[i] + arr[low] >= a) --low;
        while (high > low && arr[i] + arr[high] > b) --high;
        // cout<<i<<" "<<low<<" "<<high<<endl;
        cnt += (high-low);
        ++i;
    }
    return cnt;
}
int main()
{
    int a[]={1,3,5,9};
    int k=countPair(a,4,10,11);
    cout<<k<<endl;

}