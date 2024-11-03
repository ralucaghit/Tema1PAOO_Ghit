#include <iostream>
using namespace std;

class Vector {
private:
    int* elements;
    int size;

public:
    // Constructor pentru a inițializa un vector de dimensiune fixă
    Vector(int dim) : size(dim) {
        elements = new int[size];
        for (int i = 0; i < size; i++) {
            elements[i] = 0;  // Inițializăm fiecare element cu 0
        }
    }

    
    Vector(int dim, int vals[]) : size(dim) {
        elements = new int[size];
        for (int i = 0; i < size; i++) {
            elements[i] = vals[i];
        }
    }

    //destructor pentru a elibera memoria
    ~Vector() {
        delete[] elements;
    }

    // metoda pentru adunare
    Vector add(const Vector& other) const {
        Vector result(size);
        for (int i = 0; i < size; i++) {
            result.elements[i] = elements[i] + other.elements[i];
        }
        return result;
    }

    // metoda pt afisarea vectorului
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << elements[i]<<" ";
        }
        cout<<endl;
        
    }
};

int main() {
    // initializarea vectorilor
    int elems1[] = {1, 2, 3};
    int elems2[] = {4, 5, 6};
    int dim = 3;

    Vector v1(dim, elems1);
    Vector v2(dim, elems2);

    v1.print();
    v2.print();
    Vector sum = v1.add(v2);
    cout << "Suma vectorilor: ";
    sum.print();

    return 0;
}
