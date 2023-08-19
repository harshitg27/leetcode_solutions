// Quick sort in C++

#include <iostream>
using namespace std;\

int partition (int arr[], int low, int high)
{
    // Your code here

    int pivot = arr[low] ;

    int cnt = 0 ;
    for(int i = low+1  ; i<=high ; i++){
        if(pivot >= arr[i]){
            cnt++ ;
        }
    }
    int pivotindex = low + cnt ;

    swap(arr[pivotindex] , arr[low]);

    //   left or right part

    int i = low , j = high ;

    while(i<pivotindex && j>pivotindex){
        while(arr[i]<pivot){
            i++ ;
        }
        while(arr[j]> pivot){
            j-- ;
        }

        if(i<pivotindex && j>pivotindex){
            swap(arr[i++] , arr[j--]) ;
        }
    }

    return pivotindex ;
}

void quickSort(int arr[], int low, int high)
{
    // code here
    if(low>= high)
        return ;

    int p = partition(arr , low , high);

    quickSort(arr , low , p-1) ;

    quickSort(arr , p+1 , high) ;

}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int data[] = {8, 7, 6, 1, 0, 9, 2};
  int n = sizeof(data) / sizeof(data[0]);

  cout << "Unsorted Array: \n";
  printArray(data, n);

  // perform quicksort on data
  quickSort(data, 0, n - 1);

  cout << "Sorted array in ascending order: \n";
  printArray(data, n);
  return 0 ;
}
