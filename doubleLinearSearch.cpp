#include <iostream>
#include <vector>
using namespace std;

vector<int> doubleLinearSearch (vector <int> array, int searchValue) {
    // create an array to store the index of the search findings.
    vector <int> search_findings;
    //initialize a variable to store the number of elements found.
    int index_found = 0;

    //while loop iterates through every element of the array
    int i = 0;
    while(i< array.size()){
        //checking whether the array element is equal to the search value.
        if (array[i] == searchValue){
            //adding the element into search_findings vector if found any searching value
            search_findings.push_back(i);
            index_found ++;
            //checking if the number of found elements is equal to 2 and breaking the loop if so
            if (index_found == 2)
                break;

        }
        //increment i++ to move to the next element.
        i++;
    }
    //clearing the search and adding -1 to search finding if less than 2 indexes are found.
    if (index_found < 2){
        search_findings.clear();
        search_findings.push_back(-1);
    }
    return search_findings;
}




int main(){
    vector<int> array {10, 50, 1, 9, 15, 16, 16, 16, 16, 20, 2, 5};
    int searchValue = 1;
    vector<int> test = doubleLinearSearch(array,searchValue);
    for (int i : test) {
        cout << i << " ";

    }

    return 0;
}

