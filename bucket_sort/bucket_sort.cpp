#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> buckets(1000, vector<int>(1000));
int max_bucket = 0;


int count_bits(int n){
    int count = 0;
    while(n){
        if(n % 2 == 1)
            count++;
        n = n >> 1;
    }
    return count;
}

void bucket_sort(int* a, int n){
    for(int i = 0; i < n; i++){
        int bucket_index = count_bits(a[i]);
        buckets[bucket_index][0]++; // increment bucket counter
        int bucket_counter = buckets[bucket_index][0];
        buckets[bucket_index][bucket_counter] = a[i];
        max_bucket = (bucket_index >  max_bucket) ? bucket_index : max_bucket;
    }
}

void sort_and_print_buckets(){
    for(int i = 1; i <= max_bucket; i++){
        // sort here!
        sort(buckets[i].begin() + 1, buckets[i].begin() + buckets[i][0] + 1);
        for(int j = 1; j <= buckets[i][0]; j++){
            cout << buckets[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){

    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    bucket_sort(arr, n);
    sort_and_print_buckets();
    //cout << "max_bucket: " << max_bucket << endl;
    //for(int i = 0; i < max_bucket; .i++)


    return 0;
}
