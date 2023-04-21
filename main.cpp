#include <iostream>
#include <ctime>

void heapify(int array[], int sz, int curr);
void heapSort(int array[], int n);
void print(int array[], int n);

int main() {

    int arr1[150000];

    for (int i = 0; i < 150000; i++) {

        arr1[i] = i+1;
    
    }
    int arr2[]{ 3, 67, 43, 23, 45, 67, 5, 9, 41, 66 };

    heapSort(arr2, 10);
    
    std::cout << "Sorted array: " << std::endl;
    print(arr2, 10);

    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    clock_t start1, end1;

    start1 = clock();
    heapSort(arr1, n1);
    end1 = clock();
    int t1 = end1 - start1;

    std::cout << "Sorted array: " << (double)t1/CLOCKS_PER_SEC << std::endl;

    for (int i = 0; i < 150000; i++) {

        arr1[i] = rand()%10000;

    }

    start1 = clock();
    heapSort(arr1, n1);
    end1 = clock();
    int t2 = end1 - start1;

    std::cout << "Random array: " << (double)t2/CLOCKS_PER_SEC << std::endl;

    for (int i = 0; i < 150000; i++) {

        arr1[i] = 150000-i;

    }

    start1 = clock();
    heapSort(arr1, n1);
    end1 = clock();
    int t3 = end1 - start1;

    std::cout << "Reversed sorted array: " << (double)t3/CLOCKS_PER_SEC << std::endl;

    system("pause");
    return 0;

}

void heapify(int array[], int sz, int curr) {

    int larg = curr;

    int left = 2 * curr + 1;
    int right = 2 * curr + 2;

    if (left < sz && array[left] > array[larg]) {

        larg = left;

    }

    if (right < sz && array[right] > array[larg]) {

        larg = right;

    }

    if (larg != curr) {

        std::swap(array[curr], array[larg]);
        heapify(array, sz, larg);

    }

}

void heapSort(int array[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--) {

        heapify(array, n, i);

    }

    for (int i = n - 1; i >= 0; i--) {

        std::swap(array[0], array[i]);
        heapify(array, i, 0);

    }

}

void print(int array[], int n) {

    for (int i = 0; i < n; i++) {

        std::cout << array[i] << " ";

    }

    std::cout << std::endl;

}
