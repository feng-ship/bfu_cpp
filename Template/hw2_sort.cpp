#include <iostream>
using namespace std;
template <class T>
void Input(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }
}
template <class T>
void Sort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            T temp; 
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
template <class T>
void Output(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            cout << arr[i] << ", ";
        } else {
            cout << arr[i];
        }
    }
    cout << endl;
}
int main() {
    const int LEN = 5;
    int type;
    while (std::cin >> type) {
        switch (type) {
            case 0: {
                int a1[LEN];
                Input<int>(a1, LEN); 
                Sort<int>(a1, LEN); 
                Output<int>(a1, LEN);
                break;
            }
            case 1: {
                char a2[LEN];
                Input(a2, LEN); 
                Sort(a2, LEN); 
                Output(a2, LEN); 
                break; 
            }
            case 2: {
                double a3[LEN];
                Input(a3, LEN); 
                Sort(a3, LEN); 
                Output(a3, LEN);
                break;
            }
        }
    }

    return 0;
}