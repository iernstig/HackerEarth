#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

void print_vector(vector<int> arr, int n){
    for(int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << " ";
}

long maximum_bottles_to_fill(vector<long> bottles, long n, long water){
    sort(bottles.begin(), bottles.begin() + n);
    long sum=0;
    long count=0;
    int i = 0;
    while(sum<=water-bottles[i]&&i<n){
        sum+=bottles[i];
        count++;
        i++;
    }
    return count;
}


int main(){
    // correct output for data.txt = 2447
    int testCases, numberOfBottles;
    long water;
    /*
    cin >> testCases;
    cin >> numberOfBottles;
    cin >> water;
    */
    int tmp;

    ifstream file ("data.txt");
    file >> testCases;
    file >> numberOfBottles;
    file >> water;
    vector<long> bottles;

    while(file){
        file >> tmp;
        bottles.push_back(tmp);
    }

    cout << "water: " << water << endl;
    cout << "numOfBottles" << numberOfBottles << endl;

    cout << maximum_bottles_to_fill(bottles, numberOfBottles, water) << endl;

    /*
    for(int i = 0; i < testCases; i++){
    vector<int> bottles;
    for(int j = 0; j < numberOfBottles; j++){
    cin >> tmp;
    bottles.push_back(tmp);
}
cout << maximum_bottles_to_fill(bottles, numberOfBottles, water);
}
*/




return 0;
}

/*
int main(){



return 0;
}

*/
