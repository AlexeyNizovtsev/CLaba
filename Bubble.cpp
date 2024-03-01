#include <iostream>
#include <vector>

template<typename T>
void bubbleSort(T array[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                T t = array[j];
                array[j] = array[j + 1];
                array[j + 1] = t;
            }
        }
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

    bubbleSort(vect.data(), size);

    printArr(vect.data(), size);

    return 0;
}