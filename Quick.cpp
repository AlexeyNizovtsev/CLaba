#include <iostream>
#include <vector>
#include <random>


template <typename T>
int Part(T array[], int begin, int end) {
    T pivot = array[end];
    int i = begin - 1;

    for (int j = begin; j <= end - 1; ++j) {
        if (array[j] < pivot) {
            i++;
            std::swap(array[i], array[j]);
        }
    }

    std::swap(array[i + 1], array[end]);
    return i + 1;
}

template<typename T>
int randPivot(T array[], int begin, int end) {
    srand(time(0));
    int randIndex = begin + rand() % (end - begin);
    std::swap(array[randIndex], array[end]);
    return Part(array, begin, end);
}


template <typename T>
void quickSort(T array[], int begin, int end) {
    if (begin < end) {
        int pivot = randPivot(array, begin, end);

        quickSort(array, begin, pivot - 1);
        quickSort(array, pivot + 1, end);
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
    std::cout << "Type array size: ";
    std::cin >> size;

    std::vector<double> vect(size);

    std::cout << "Type the elements: \n";
    for (int i = 0; i < size; i++) {
        std::cout << "Element " << i + 1 << ": ";
        std::cin >> vect[i];
    }

    quickSort(vect.data(), 0, size-1);
    
    printArr(vect.data(), size);

    return 0;
}