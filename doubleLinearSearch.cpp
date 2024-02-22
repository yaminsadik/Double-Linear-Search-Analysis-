//
// Created by yamin on 2/21/2024.
//
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