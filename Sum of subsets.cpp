#include <iostream>
#include <vector>

using namespace std;

// Function to print a subset
void printSubset(const vector<int>& subset) {
    cout << "{ ";
    for (int i = 0; i < subset.size(); i++) {
        cout << subset[i] << " ";
    }
    cout << "}" << endl;
}

// Recursive utility function to find subsets that sum up to the given target
void sumOfSubsetsUtil(const vector<int>& set, vector<int>& subset, int index, int target) {
    // If the target sum is reached, print the subset
    if (target == 0) {
        printSubset(subset);
        return;
    }

    // If the target sum is less than zero, return
    if (target < 0) {
        return;
    }

    // Consider each element starting from the current index
    for (int i = index; i < set.size(); i++) {
        // Include the current element in the subset
        subset.push_back(set[i]);

        // Recur with the reduced target and the next index
        sumOfSubsetsUtil(set, subset, i + 1, target - set[i]);

        // Backtrack: remove the current element from the subset
        subset.pop_back();
    }
}

// Function to find all subsets of a set that sum up to the given target
void sumOfSubsets(const vector<int>& set, int target) {
    vector<int> subset;
    sumOfSubsetsUtil(set, subset, 0, target);
}

int main() {
    vector<int> set = {10, 7, 5, 18, 12, 20, 15}; // Example set
    int target = 35; // Example target sum

    cout << "Subsets of the given set that sum up to " << target << " are:" << endl;
    sumOfSubsets(set, target);

    return 0;
}
