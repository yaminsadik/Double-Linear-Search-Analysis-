#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

const int NOT_FOUND = -1;
unsigned long compCount = 0; // global counter
int total_hits = 0;
int total_misses = 0;
int min_steps = INT_MAX; // initializing with the maximum possible value.

// generate random values between min and max
int random_value(int min, int max);

// takes a vector and an int value and returns the index if found
vector<int> doubleLinearSearch(vector<int> array, int searchValue);


int main() {

    // Use current time as seed for random generator
    srand(time(0));

    const long SIMUL_SIZE = 1000;
    const long VECTOR_SIZE[] = {10000, 20000, 35000, 50000, 75000, 100000};
    const int MIN = 0, MAX = 15000;

//    vector<int> array;
    double average_steps= 0;

    for (int i = 0; i < 6; i++) {
        // Reset counters before each iteration.
        long total_steps = 0;
        total_steps = 0;
        total_misses = 0;
        total_hits = 0;
        min_steps = INT_MAX;
        //main simulation loop
        for (long simul_index = 0; simul_index<SIMUL_SIZE; simul_index++)
        {
//            array.clear();
            compCount = 0; // global variable to count number of steps to complete search

            vector<int> array;
            // filling the vector with VECTOR_SIZE random values
            for (long array_index = 0; array_index<VECTOR_SIZE[i]; array_index++)
            {
                int ranValue = random_value(MIN, MAX);
                array.push_back(ranValue);

            }

            // sort the array elements in ascending order
            sort(array.begin(), array.end());

            // generate a random search value
            int search_value =random_value(MIN, MAX);

            // call the search function
            vector <int> search_index = doubleLinearSearch(array, search_value);
            //claculate hits and misses
            if (search_index[0] != -1 && search_index[1] != -1)
                total_hits++;
            else
                total_misses++;
            //update minimum steps
            if (compCount<min_steps)
                min_steps = compCount;

            // increment the total steps
            total_steps = total_steps + compCount;

        }

        // determining the average steps
        average_steps = total_steps/static_cast<double> (SIMUL_SIZE);

        cout << "For vector size " << VECTOR_SIZE[i] << ":\n";
        cout << "Average steps: " << average_steps << endl;
        cout << "Total hits: " << total_hits << endl;
        cout << "Total misses: " << total_misses << endl;
        cout << "Minimum steps: " << min_steps << endl;
        cout << "-----------------------------\n";

    }
    // main simulation loop;


    return 0;
}



// generate random values between min and max (inclusive)
int random_value(int min, int max)
{
    return min + rand() % (max - min);
}



// takes a vector and an int value and returns the index if found
vector<int> doubleLinearSearch (vector <int> array, int searchValue) {
    // create an array to store the index of the search findings.
    vector <int> search_findings;
    //initialize a variable to store the number of elements found.
    int index_found = 0;

    //while loop iterates through every element of the array
    int i = 0;
    while(i< array.size()){
        compCount++;
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