/**This program prints out all permutations of a given string.
Author: Eric Deck
*/

#include <iostream>
using namespace std;

//Count to keep track of number of permutations
int count = 0;
//Sets the low and high index values and calls the permute function
void permute(const string & str);
//Prints out all permutations of a given string
void permute(const string & str, int low, int high);
//Checks to see if we need to swap
bool checkSwap(string str, int low, int current);

int main(){
    permute("Hello");
}

void permute(const string & str){
    int high = str.size();
    int low = 0;
    permute(str, low, high-1);
    cout << "There are " << count << " permutations of " << str <<endl;

}

void permute(const string & str, int low, int high){
    string newStr = str;
    if(low == high){
        count ++;
        cout << newStr << endl;
    }
    else{
        for(int i = low; i <= high; i++){
            bool check = checkSwap(newStr, low, i);
            if(check){
                swap(newStr[low], newStr[i]);
                permute(newStr, low+1, high);
            }
        }
    }
}

bool checkSwap(string str, int low, int current){
    for(int i = low; i < current; i++){
        if(str[i] == str[current]){
            return 0;
        }
    }
    return 1;
}