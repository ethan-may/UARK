#include "heap.h"

int main()
{
    Heap heap;
    
    int N;
    cout << "Enter size value: ";
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        int num = random() % N;
        heap.Insert(num);
        heap.Print();
    }
    
    int value;
    cout << endl;
    while (!(heap.IsEmpty()))
    {
        heap.Remove(value);
        cout << "Value Removed: " << value << endl;
        heap.Print();
    }

    return 0;
}
