#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


string find_palindromic_substr_brute_force(string str){
    int maxlen = 1;
    string palindromic_substr;
    for(int center = 0; center < str.length(); center++){

        int add_len = 0;
        int left = center - add_len;
        int right = center + add_len;
        int substr_len = 1;

        while(left > 0 && right < str.length()){
            add_len++;
            left = center - add_len;
            right = center + add_len;

            if(str[left] == str[right])
                substr_len++;
            else
                break;
        }


        if(substr_len > maxlen){
            palindromic_substr = str.substr(left, right + 1);
            maxlen = substr_len;
        }
    }

    return palindromic_substr;
}


int main(){
    ifstream file("../data/palindromic.txt");
    string s;
    file >> s;
    cout << find_palindromic_substr_brute_force(s) << endl;
    return 0;
}
