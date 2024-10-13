#include <iostream>
#include <list>
using namespace std;

int main(){

    list<int> list1 = {1, 2, 4, 6, 7};

    // Print the first element using iterator
    auto itr = list1.begin();
    cout << *itr << endl;

    // Print the last element using reverse iterator
    auto rev_itr = list1.rbegin();
    cout << *rev_itr << endl;

    // Advance iterator by 2 positions and print the element
    advance(itr, 2);
    cout << *itr << endl;

    for(auto num : list1){  // using range based loop
        cout<< num << " ";
    } cout << endl;

    for(auto itr = list1.begin() ; itr != list1.end() ; itr++){ //using iterator
        cout << *itr << " ";
    }
    cout << endl;

    //inserting elements
    auto itr1 = list1.begin();
    advance(itr1, 2);

    list1.insert(itr1, 55);
    for(auto itr1 = list1.begin() ; itr1 != list1.end() ; itr1++){ //using iterator
        cout << *itr1 << " ";
    }
    cout << endl;

    list1.insert(itr1, 2, 55);
    for(auto itr1 = list1.begin() ; itr1 != list1.end() ; itr1++){ //using iterator
        cout << *itr1 << " ";
    }
    cout << endl;

    // deleting 
    auto itr2 = list1.begin();
    advance(itr2, 2);
    list1.erase(itr2);
    for(auto itr2 = list1.begin() ; itr2 != list1.end() ; itr2++){ //using iterator
        cout << *itr2 << " ";
    }
    cout << endl;
    



    return 0;
}
