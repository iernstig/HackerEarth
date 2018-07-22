#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#define SIZE 100005

string separate_string(string &str){
    string r = "#";
    for(int i = 0; i < str.length(); i++){
        r.push_back(str[i]);
        r.push_back('#');
    }
    return r;
}

void manachers_algorithm(string str){
    str = separate_string(str); // done to make sure odd parity of str
    vector<int> ref_list(SIZE*2);

    int c = 0;
    int r = 0;
    int largest, largest_center;


    for(int i = 0; i < str.length(); i++){

        int i_mirror = c - (i - c);

        if(i < r)
            ref_list[i] = min(r - i, ref_list[i_mirror]);
        else
            ref_list[i] = 0;

        while(str[i + 1 + ref_list[i]] == str[i - 1 - ref_list[i]])
            ref_list[i]++;

        if(i + ref_list[i] > r){
            c = i;
            r = i + ref_list[i];
        }


        if(ref_list[i] > largest){
            largest = ref_list[i];
            largest_center = i;
        }
    }

    int palindrome_start = largest_center - largest + 1;
    int palindrome_stop  = largest_center + largest;

    cout << largest << endl;

    for(int i = palindrome_start; i < palindrome_stop; i += 2)
        cout << str[i];

    cout << endl;

}

int main(){
    ifstream file("../data/palindromic_hard.txt");
    string str;
    file >> str;
    //cout << "str: " << str << endl;
    manachers_algorithm(str);
    return 0;
}
