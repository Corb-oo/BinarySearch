// Binary Search is clever algorithm that is much more efficent than the linear search. It's only requriment is that the values in the array be sorted in order. Instead of testing the array's first element, this algorithm starts with the element in the middle. If that element happens to contain the desired value, then the search is over. Otherwise, the value in the middle element is either greater than or less the value being searched for. If it is greater than, then the desired value (if it is in the list) will be found somewhere in the first half of the array. If it is less than, then the desired value (if it is in the array) will be found somewhere in the last half of the array. In either case, half of the array's elements have been elimated from furhter searching. 

// If desired value wasn't found in the middle element, the procedure is repeated for the half of the array that potentially contains the value. For instance, if the last half of the array is to be searched, the algorithm immediatlely tests its middle element. If the desired value isn't found there, the search is narrowed to the quarter of the array that resides beofre or after that element. This process continues until either the value being searched for is found, or there are no more elements to test.

// psueudcode for the function that performs that performs the binary search on an array.

// set first to 0
// set last to the last subscript in the array
// set found to false
// set position to -1
// while found is not true and first is less than or equal to last
    // set middle to the subscript halfway between array[first] and array[last]
    // If array[middle] equals the desired value
        // Set found to true
        // set position to middle
    // Else if array[middle] id greater than the desired value
        // Set last to middle - 1
    // Else 
        // set first to middle + 1
    // End if
// End while
// return position

#include <iostream>
using namespace std;

const int SIZE = 20;

// binaray search example function.
int binarySearch(const int array[], int numElems, int value) {
    int first = 0; // first array element
    int last = numElems - 1; // last array element
    int middle; // midpoint search
    int position = -1; // position of search value
    bool found = false; // flag

    while(!found && first <= last) {
        middle = (first+last)/2; // // calcuate the midpoint

        if(array[middle]==value){ // if value is found at mid
            found = true;
            position = middle;
        }
        else if(array[middle] > value) { // if value is in the lower half
            last = middle - 1;
        }
        else { // if value is in the upper half
            first = middle + 1;
        }
    }
    return position;
}

int main() {

    // Array with employee IDs sorted in ascending order.
    int idNums[SIZE] = {101, 142, 147, 189, 199, 207, 222,
        34, 289, 296, 310, 319, 388, 394,
        417, 429, 447, 521, 536, 600};
    
    int results;
    int empID;

    cout << "Enter your employee ID you wish to search for: ";
    cin >> empID;

    results = binarySearch(idNums, SIZE, empID);

    if(results == -1) {
        cout << "That number does not exist in the array. \n";
    }
    else {
        cout << "That ID is found at element " << results;
        cout << " in the array.\n";
    }

    return 0;
}

