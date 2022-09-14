#include <cstdlib>
#include <cstdio>
#include <cstring>

class Array {
public:
    Array() {
        capacity = 10;
        arr = (int*) malloc(capacity * sizeof(int*));
    }

    Array(size_t initialCapacity) {
        capacity = initialCapacity;
        arr = (int*) malloc(capacity * sizeof(int*));
    }

    Array(Array const &array) {
        size = array.size;
        capacity = array.capacity;
        arr = (int*) malloc(capacity * sizeof(int*));
        operator=((Array &) array);
    }

    ~Array() {
        free(arr);
    }

    Array operator= (Array& array) {
        if (this != &array) {
            memcpy(arr, array.arr, sizeof(*arr) * capacity);
        }
        return *this;
    }

    void At(size_t n) {
        if (n > size) {
            printf("There is no such element\n");
        } else {
            printf("%d\n", arr[n]);
        }
    }

    void PushBack(int X) {
        if (size == capacity) {
            capacity *=2;
            int * tmp = (int*)realloc(arr, capacity);
            if (!tmp) {
                exit(1);
            }
            arr = tmp;
        }
        arr[size] = X;
        size++;
    }

    void Insert(int X, size_t n) {
        if (size == capacity) {
            capacity *=2;
            int * tmp = (int*)realloc(arr, capacity);
            if (!tmp) {
                exit(1);
            }
            arr = tmp;
        }
        for (size_t i = size; i > n; --i ) {
            arr[i] = arr[i - 1];
        }
        arr[n] = X;
        size++;
    }

    void Print() {
        for (size_t i = 0; i < size; ++i) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

private:
    int* arr = nullptr;
    size_t size = 0ull;
    size_t capacity = 0ull;
};

int main() {
    int menu = 0, x;
    unsigned long long n;
    printf("Enter the initial size of the array:\n");
    scanf("%d", &x);
    Array a(x);
    while (menu != 4) {
        printf("1. Add an element to the end of the array\n");
        printf("2. Insert an item into the desired cell\n");
        printf("3. Find out which element is in the cell\n");
        printf("4. End the program\n");
        scanf("%d", &menu);
        switch (menu) {
            case 1:
                printf("Enter a number:\n");
                scanf("%d", &x);
                a.PushBack(x );
                break;
            case 2:
                printf("Enter a number:\n");
                scanf("%d", &x);
                printf("Enter the cell number:\n");
                scanf("%llu", &n);
                a.Insert(x, n);
                break;
            case 3:
                printf("Enter the cell number:\n");
                scanf("%llu", &n);
                a.At(n);
                break;
            default:
                break;
        }
        a.Print();
    }
    Array b = a;
    a.Print();
    b.Print();
}