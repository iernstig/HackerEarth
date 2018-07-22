#include <iostream>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

void print_array(ll *arr, ll n){
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void print_heap(ll *arr, ll n){
    int nodeIndex = 0;
    int levelDelimiter = 2;

    while(nodeIndex < n){
        cout << arr[nodeIndex++] << " ";
        if(nodeIndex == levelDelimiter - 1){
            cout << endl;
            levelDelimiter = levelDelimiter*2;
        }
    }

    cout << endl;
}

void swap(ll *arr, ll i, ll j){
    ll tmp = arr[i];
    arr[i]  = arr[j];
    arr[j]  = tmp;
}


void heapify(ll *arr,ll n, ll initIndex){
    ll maxIndex   = initIndex;
    ll leftIndex  = 2*initIndex + 1;
    ll rightIndex = 2*initIndex + 2;

    if(leftIndex < n && arr[leftIndex] > arr[maxIndex])
        maxIndex = leftIndex;

    if(rightIndex < n && arr[rightIndex] > arr[maxIndex])
        maxIndex = rightIndex;

    if(maxIndex != initIndex){
        swap(arr, maxIndex, initIndex);
        heapify(arr, n, maxIndex);
    }

}

void sift_up(ll *arr, ll n, ll index){
    while(index != 0){
        if(index % 2 == 0)
            index = (index/2) - 1;
        else
            index = index/2;

        heapify(arr, n, index);
    }
}

void build_heap(ll *arr, ll n){
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}


void heap_sort(long long array[], long long n){
    ll *ptr = &array[0];

    for(int i = 1; i <= n; i++){
        build_heap(ptr, n - i);
        ptr++;
    }
}


void print_three_richest_people(ll *arr, ll n){

    if (n < 3)
        cout << "-1" << endl;
    else if(n == 3)
        build_heap(arr, n);
    else{
        sift_up(arr, n, n);
        ll max1 = 0;
        ll max2 = (arr[1] > arr[2]) ? 1 : 2;
        ll max2left  = max2*2 + 1;
        ll max2right = max2*2 + 2;

        ll max3 = (arr[2] > arr[1]) ? 1 : 2;
        if(max2left < n)
            max3    = (max3   > arr[max2left]) ? max3 : max2left;
        if(max2right < n)
            max3    = (max3   > arr[max2right]) ? max3 : max2right;

        cout << arr[max1] << " " << arr[max2] << " " << arr[max3] << endl;
    }
        /*
    else{ // this logic is faulty
        turn_into_heap(arr, n);
        ll *ptr = &arr[0];
        for(int i = 0; i < 3; i++){
            cout << *ptr << " ";
            ptr++;
            turn_into_heap(ptr, n - i - 1);
        }
        cout << endl;
    }
    */
}

int main(){

    ll n;
    cin >> n;
    ll* arr = new ll[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        print_three_richest_people(arr, i + 1);
    }

    return 0;
}
