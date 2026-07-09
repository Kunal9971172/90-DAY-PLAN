#include <iostream>
#include <vector>
#include <numeric>      // Required for std::accumulate
#include <algorithm>    // Required for std::sort, std::reverse, etc.

using namespace std;

// Helper function to print a vector
void printVector(const string& message, const vector<int>& vec) {
    cout << message << ": [";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "] (Size: " << vec.size() << ", Capacity: " << vec.capacity() << ")\n";
}

// 1. Initialization and Declaration of Vector
void demoInitialization() {
    cout << "\n--- 1. VECTOR INITIALIZATION ---\n";

    // A. Empty Vector
    // Time Complexity: O(1)
    vector<int> v1;
    printVector("v1 (Empty)", v1);

    // B. Vector with size N (all elements initialized to 0 by default)
    // Time Complexity: O(N) where N is the size
    int n = 5;
    vector<int> v2(n);
    printVector("v2 (Size 5, default 0)", v2);

    // C. Vector with size N and all elements initialized to a specific value
    // Time Complexity: O(N)
    vector<int> v3(n, 7);
    printVector("v3 (Size 5, initialized to 7)", v3);

    // D. Vector initialized using an Initializer List
    // Time Complexity: O(N)
    vector<int> v4 = {1, 2, 3, 4, 5};
    printVector("v4 (Initializer List)", v4);

    // E. Creating a vector from an existing array
    // Time Complexity: O(N)
    int arr[] = {10, 20, 30, 40, 50};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    vector<int> v5(arr, arr + arr_size);
    printVector("v5 (From array)", v5);

    // F. Copying another vector (Copy Constructor)
    // Time Complexity: O(N)
    vector<int> v6(v4);
    printVector("v6 (Copy of v4)", v6);
}

// 2. Element Access
void demoElementAccess() {
    cout << "\n--- 2. ELEMENT ACCESS ---\n";
    vector<int> v = {10, 20, 30, 40, 50};
    printVector("Vector v", v);

    // A. Using [] operator (No bound checking, extremely fast)
    // Time Complexity: O(1)
    cout << "v[2] (using []): " << v[2] << "\n";

    // B. Using .at() (Checks bounds, throws out_of_range exception if invalid)
    // Time Complexity: O(1)
    try {
        cout << "v.at(2) (using .at()): " << v.at(2) << "\n";
        // v.at(10); // Un-commenting this will throw an error safely
    } catch (const out_of_range& e) {
        cout << "Exception: " << e.what() << "\n";
    }

    // C. Front and Back element access
    // Time Complexity: O(1)
    cout << "First Element (v.front()): " << v.front() << "\n";
    cout << "Last Element (v.back()): " << v.back() << "\n";

    // D. Data pointer (Underlying array pointer)
    // Time Complexity: O(1)
    int* ptr = v.data();
    cout << "First element using data(): " << *ptr << "\n";
}

// 3. Iterators
void demoIterators() {
    cout << "\n--- 3. ITERATORS ---\n";
    vector<int> v = {10, 20, 30, 40, 50};

    // A. Forward traversal using iterators
    // v.begin() points to the first element
    // v.end() points to one past the last element
    cout << "Forward Traversal: ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";

    // B. Reverse traversal using reverse iterators
    // v.rbegin() points to the last element (starts reverse traversal)
    // v.rend() points to one before the first element
    cout << "Reverse Traversal: ";
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
}

// 4. Capacity and Size Properties
void demoCapacityAndSize() {
    cout << "\n--- 4. CAPACITY & SIZE ---\n";
    vector<int> v;

    // Size vs Capacity:
    // Size is the number of elements actually present.
    // Capacity is the total space allocated (can hold elements without reallocation).
    cout << "Initial size: " << v.size() << ", Capacity: " << v.capacity() << "\n";

    // Pushing elements to see how capacity doubles dynamically in C++ (compiler dependent, usually 1.5x or 2x)
    for (int i = 1; i <= 5; ++i) {
        v.push_back(i);
        cout << "Pushed " << i << " -> Size: " << v.size() << ", Capacity: " << v.capacity() << "\n";
    }

    // A. Check if vector is empty
    // Time Complexity: O(1)
    cout << "Is vector empty? " << (v.empty() ? "Yes" : "No") << "\n";

    // B. Resize the vector (increases or decreases size)
    // Time Complexity: O(K) where K is the difference between current and new size
    v.resize(3);
    printVector("After resize(3)", v);

    // C. Reserve capacity (avoids overhead of frequent reallocations)
    // Time Complexity: O(N) if reallocation occurs, otherwise O(1)
    // Extremely useful in competitive programming/DSA when max size is known beforehand.
    v.reserve(100);
    cout << "After reserve(100) -> Size: " << v.size() << ", Capacity: " << v.capacity() << "\n";

    // D. Shrink to fit (reduces capacity to match size)
    // Time Complexity: O(N)
    v.shrink_to_fit();
    cout << "After shrink_to_fit() -> Size: " << v.size() << ", Capacity: " << v.capacity() << "\n";
}

// 5. Modifiers (Insertion, Deletion, Swapping)
void demoModifiers() {
    cout << "\n--- 5. MODIFIERS (INSERT/ERASE) ---\n";
    vector<int> v = {10, 20, 30};
    printVector("Initial vector v", v);

    // A. push_back: Insert element at end
    // Time Complexity: O(1) amortized
    v.push_back(40);
    printVector("After push_back(40)", v);

    // B. pop_back: Remove element from end
    // Time Complexity: O(1)
    v.pop_back();
    printVector("After pop_back()", v);

    // C. insert: Insert at a specific position (using iterator)
    // Time Complexity: O(N) due to shifting elements to the right
    // Inserting at the beginning
    v.insert(v.begin(), 5);
    printVector("After insert at begin (5)", v);

    // Inserting at index 2 (v.begin() + 2)
    v.insert(v.begin() + 2, 15);
    printVector("After insert at index 2 (15)", v);

    // Inserting multiple copies of a value
    v.insert(v.begin() + 1, 2, 99); // inserts two 99s starting at index 1
    printVector("After inserting two 99s at index 1", v);

    // D. erase: Delete element at a specific position or range
    // Time Complexity: O(N) due to shifting elements to the left
    // Erase single element at index 1 (second element)
    v.erase(v.begin() + 1);
    printVector("After erasing element at index 1", v);

    // Erase a range: [start, end)
    v.erase(v.begin() + 1, v.begin() + 3); // deletes elements at index 1 and 2
    printVector("After erasing range [1, 3)", v);

    // E. clear: Remove all elements from the vector
    // Time Complexity: O(N) to call destructors of elements
    v.clear();
    printVector("After clear()", v);
    cout << "Is vector empty after clear()? " << (v.empty() ? "Yes" : "No") << "\n";
}

// 6. Common Sorting and Manipulation Algorithms (Very critical for DSA)
void demoAlgorithms() {
    cout << "\n--- 6. ALGORITHMS ON VECTORS ---\n";
    vector<int> v = {40, 10, 50, 20, 30};
    printVector("Original vector v", v);

    // A. Sorting a vector (Ascending Order)
    // Time Complexity: O(N log N)
    // Space Complexity: O(log N) (inside std::sort)
    sort(v.begin(), v.end());
    printVector("After ascending sort()", v);

    // B. Sorting a vector (Descending Order)
    // Time Complexity: O(N log N)
    sort(v.begin(), v.end(), greater<int>());
    printVector("After descending sort()", v);

    // C. Reversing a vector
    // Time Complexity: O(N)
    reverse(v.begin(), v.end());
    printVector("After reverse()", v);

    // Let's sort it back to ascending for binary search demonstration
    sort(v.begin(), v.end());
    printVector("Sorted vector for searching", v);

    // D. Binary Search (Check if element exists)
    // Time Complexity: O(log N) - Vector must be sorted!
    bool found = binary_search(v.begin(), v.end(), 30);
    cout << "Binary Search for 30: " << (found ? "Found" : "Not Found") << "\n";

    // E. Lower Bound: Returns iterator to first element >= key
    // Time Complexity: O(log N)
    auto lb = lower_bound(v.begin(), v.end(), 30);
    if (lb != v.end()) {
        cout << "Lower bound of 30: " << *lb << " at index " << (lb - v.begin()) << "\n";
    }

    // F. Upper Bound: Returns iterator to first element > key
    // Time Complexity: O(log N)
    auto ub = upper_bound(v.begin(), v.end(), 30);
    if (ub != v.end()) {
        cout << "Upper bound of 30: " << *ub << " at index " << (ub - v.begin()) << "\n";
    }

    // G. Min and Max element
    // Time Complexity: O(N)
    auto min_it = min_element(v.begin(), v.end());
    auto max_it = max_element(v.begin(), v.end());
    cout << "Min Element: " << *min_it << "\n";
    cout << "Max Element: " << *max_it << "\n";

    // H. Sum of elements (std::accumulate)
    // Time Complexity: O(N)
    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "Sum of elements: " << sum << "\n";
}

// 7. Vector Parameter Passing Best Practices
// A. Pass by value (Avoid this unless copy is needed! It duplicates the data.)
// Time Complexity: O(N)
void passByValue(vector<int> temp) {
    temp.push_back(100); // Only modifies the local copy
}

// B. Pass by reference (Good for modifying the vector in-place)
// Time Complexity: O(1) to pass
void passByReference(vector<int>& temp) {
    temp.push_back(100); // Modifies the original vector
}

// C. Pass by const reference (Best Practice for read-only vectors)
// Time Complexity: O(1) to pass, prevents modification
void passByConstReference(const vector<int>& temp) {
    // temp.push_back(100); // Compiler error: temp is const
    cout << "Read-only access: size is " << temp.size() << "\n";
}

void demoParameterPassing() {
    cout << "\n--- 7. PARAMETER PASSING TECHNIQUES ---\n";
    vector<int> original = {1, 2, 3};
    printVector("Original", original);

    passByValue(original);
    printVector("After passByValue", original); // No change

    passByReference(original);
    printVector("After passByReference", original); // Changed! Added 100

    passByConstReference(original);
}

int main() {
    cout << "========================================\n";
    cout << "    C++ STL VECTOR CHEATSHEET FOR DSA   \n";
    cout << "========================================\n";

    demoInitialization();
    demoElementAccess();
    demoIterators();
    demoCapacityAndSize();
    demoModifiers();
    demoAlgorithms();
    demoParameterPassing();

    cout << "\n========================================\n";
    return 0;
}
