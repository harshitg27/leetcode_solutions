// Merge sort in C++

#include <iostream>
using namespace std;\

void merge(int arr[], int l, int m, int r)
{
    // Your code here
    int len1 = m - l + 1 ;
    int len2 = r-m ;
    int first[len1] ;
    int second [len2] ;

    int k = l ;
    //   cout<<"first " ;
    for(int i = 0 ; i<len1 ; i++){
        first[i] = arr[k++] ;
        //  cout<<first[i]<<" " ;
    }
    //  cout<<endl ;
    k = m + 1 ;
    //  cout<<"second " ;
    for(int i = 0 ; i<len2 ; i++){
        second[i] = arr[k++] ;
        //  cout<<second[i]<<" " ;
    }
    //  cout<<endl ;

    //  merge two sorted array
    int index1 = 0 ;
    int index2 = 0 ;
    k=l ;
    while(index1 < len1 && index2 <len2){
        if(first[index1]<=second[index2]){
            arr[k++] =  first[index1++] ;
        }else{
            arr[k++] =  second[index2++] ;
        }
    }

    while(index1 < len1){
        arr[k++] =  first[index1++] ;
    }
    while(index2 < len2){
        arr[k++] =  second[index2++] ;
    }
}

void mergeSort(int arr[], int l, int r)
{
    //code here
    if(l>=r){
        return ;
    }
    int mid = l + (r-l)/2 ;
    // cout<<l <<r <<endl;

    mergeSort(arr , l , mid) ;
    mergeSort(arr , mid+1 , r) ;

    merge(arr , l , mid , r) ;

    }

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int arr[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, size - 1);

  cout << "Sorted array: \n";
  printArray(arr, size);
  return 0;
}
