// Sadik Yamin
// Double Linear search algorithm simulation

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int NOT_FOUND = -1;


/**
 * This funciton generates random vlaues.
 * @param min the minimum value of the range
 * @param max the maximum value of the range.
 * @return random values between min and max.
 */
int random_value(int min, int max);

/**
 * This is the function for doubleLinearSearch Algorithm.
 * @param vec is the vector that is passed by reference which will be searched through.
 * @param searchValue is the integer that the algorithm will be searching in vec
 * @param countSteps the value that will return total steps taken.
 * @return a vector of integers with the index position of each vector.
 */
vector <int> doubleLinearSearch(const vector <int> &vec, int searchValue, int & countSteps);


int main() {

    // Use current time as seed for random generator
    srand(time(0));

    const long SIMUL_SIZE = 1000;
    const int MIN = 0, MAX = 15000;

    //a vector to store the number of times the simulation will run
    vector <int> inputSizes = {10000, 20000, 35000, 50000, 75000, 100000};

    for (int i = 0; i < inputSizes.size(); ++i) {
        int n = inputSizes.at(i);
        int total_steps = 0;
        int hits = 0;
        int miss = 0;
        int min_steps = INT_MAX;

        //main simulation loop
        for (long simul_index = 0; simul_index<SIMUL_SIZE; simul_index++)
        {
            vector <int> array;

            //filling the vector with random values
            for (int array_index = 0; array_index < n ; ++array_index) {
                int values = random_value(MIN, MAX);
                array.push_back(values);

            }

            //getting a random search value
            int searchValue = random_value(MIN, MAX);
            //creating a variable for countSteps parameter and initializing to 0
            int stepCount = 0;

            //calling the doubleLinearSearch ALgorithm Function.
            vector <int> result = doubleLinearSearch(array, searchValue, stepCount);
            total_steps += stepCount;

            if (result.at(0) != NOT_FOUND)
            {
                hits ++;
            }
            else
            {
                miss ++;
            }
            if (stepCount < min_steps){
                min_steps = stepCount;
            }

        }

        // determining the average steps
        double average_steps = static_cast <double> (total_steps) /static_cast<double> (SIMUL_SIZE);




        cout << "Input Size: " << n << endl;
        cout << "Average number of steps taken: " << average_steps << endl;
        cout << "Hits: " << hits << endl;
        cout << "Misses: " << miss << endl;
        cout << "Minimum Steps: " << min_steps << endl;
        cout << "--------------------------------------" << endl;



    }


    return 0;
}



// generate random values between min and max (inclusive)
int random_value(int min, int max)
{
    return min + rand() % (max - min)+ 1;
}

//takes a vector and an int and returns two indexes max if found. Otherwise returns -1
vector <int> doubleLinearSearch(const vector <int> &vec, int searchValue, int & countSteps){
    int vecSize;
    vecSize = vec.size();
    countSteps = 0;
    vector <int> searchFindings;

    for (int i = 0; i < vecSize; ++i)
    {
        countSteps++; //incrementing steps taken to find index in the beginning of every loop.
        if (vec.at(i) == searchValue)
        {
            searchFindings.push_back(i);
        }
        else if (searchFindings.size() == 2)
        {
            break; // when the second index is found, the loop is broken.
        }
    }
    if (searchFindings.size() < 2){
        searchFindings.clear(); // clear any elements if less than 2 elements found.
        searchFindings.push_back(-1);

    }
    return searchFindings;

}