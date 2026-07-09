#include <iostream>
#include <vector>

using namespace std;

// Helper function to print a vector
void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << "\n";
}

/*
 * 1. Standard Bubble Sort (Non-Optimized)
 * Time Complexity:
 *   - Worst Case: O(N^2) (When array is sorted in reverse order)
 *   - Average Case: O(N^2)
 *   - Best Case: O(N^2) (Even if array is already sorted, it runs all comparisons)
 * Space Complexity: O(1) Auxiliary space
 */
void bubbleSortStandard(vector<int>& arr) {
    int n = arr.size();
    
    // Total n-1 passes
    for (int i = 0; i < n - 1; ++i) {
        // Last i elements are already in place, so inner loop goes up to n-i-1
        for (int j = 0; j < n - i - 1; ++j) {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/*
 * 2. Optimized Bubble Sort
 * Time Complexity:
 *   - Worst Case: O(N^2) (When array is sorted in reverse order)
 *   - Average Case: O(N^2)
 *   - Best Case: O(N) (When array is already sorted, it stops after 1 pass)
 * Space Complexity: O(1) Auxiliary space
 */
void bubbleSortOptimized(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false; // Flag to track if any swapping happened in this pass
        
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true; // Set flag to true since we swapped elements
            }
        }
        
        // IF no two elements were swapped in the inner loop, the array is already sorted.
        // We can break early to save unnecessary passes.
        if (!swapped) {
            cout << "  (Optimized: Sorted early on pass " << i + 1 << ")\n";
            break;
        }
    }
}

int main() {
    cout << "========================================\n";
    cout << "          BUBBLE SORT ALGORITHM         \n";
    cout << "========================================\n";

    // Scenario A: Unsorted array
    vector<int> data1 = {64, 34, 25, 12, 22, 11, 90};
    cout << "Original Unsorted Array:\n";
    printVector(data1);

    cout << "\nSorting using Standard Bubble Sort...\n";
    bubbleSortStandard(data1);
    cout << "Sorted Array:\n";
    printVector(data1);

    // Scenario B: Already sorted array (to demonstrate the Optimized version's early break)
    vector<int> data2 = {11, 12, 22, 25, 34, 64, 90};
    cout << "\nOriginal Already-Sorted Array:\n";
    printVector(data2);

    cout << "\nSorting using Optimized Bubble Sort...\n";
    bubbleSortOptimized(data2);
    cout << "Sorted Array:\n";
    printVector(data2);

    cout << "========================================\n";
    return 0;
}
