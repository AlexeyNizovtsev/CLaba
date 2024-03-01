#include <iostream>
#include <vector>

template <typename T>
void selectionSort(T vect[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (vect[j] < vect[min])
                min = j;
        }
        if (min != i)
            std::swap(vect[i], vect[min]);
    }
}

template<typename T>
void printArr(T array[], int size) {
    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << "  ";
    }
}
    
int main() {
    int size;
    std::cout << "Type the size: ";
    std::cin >> size;

    std::vector<double> vect(size);

    std::cout << "Type the elements: \n";
    for (int i = 0; i < size; i++) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> vect[i];
    }

    selectionSort(vect.data(), size);

    printArr(vect.data(), size);
    
    return 0;
}