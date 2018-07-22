#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;


int binary_search(vector<ll> arr, int q){
    int low = 0;
    int high = arr.size();
    int mid;
    while(low <= high){
        mid = (high + low) >> 1;
        if(q == arr[mid])
            return mid + 1;
        else if(q > arr[mid])
            low = mid;
        else if(q < arr[mid])
            high = mid;
        else
            return -1;
    }
    return -1;
}

int main(){

    int n;
    cin >> n;
    vector<ll> arr;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    if(arr[0]>arr[1])
        sort(arr.begin(), arr.end());


    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        ll searchQ;
        cin >> searchQ;
        cout << binary_search(arr, searchQ) << endl;
    }

    return 0;
}
