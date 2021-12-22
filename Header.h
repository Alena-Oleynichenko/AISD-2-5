#include <iostream>
#include <time.h>
#include <complex>
#include <iostream>
#include <string>
using namespace std;

enum class CardinalDirection { NORTH, EAST, SOUTH, WEST };

template <class T, T True, T False>
class image {

    int N, M; 
    T** data;

public:

    image() : data(nullptr), M(0), N(0) {}
    image(int colls, int rolls);
    image(const image& other);
    ~image();
    bool GetMij(int i, int j) const;    
    void SetMij(int i, int j, T new_val) const; 
    bool can_multiply(const image& m2);
    image operator+(const image& m2);
    image operator*(const image& m2);
    image operator!(); 
    image operator=(const image& m2); 
    image operator*(bool value); 
    image operator+ (bool value); 
    void random(); 
    T rand_();
    bool draw(); 
    void print();     
    double coefficient();   
    int rows() const; 
    int cols() const;
};

template <class T, T True, T False>
image< T, True, False>::image(int M, int N)
{
    if ((M < 0) || (N < 0)) throw"Invalid Index";
    this->M = M;
    this->N = N;
    data = new T * [M];
    for (int i = 0; i < M; i++)
        data[i] = new T[N];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            data[i][j] = False;
}
template <class T, T True, T False>
image < T, True, False> ::image(const image& m2) {
        this->M = m2.M;
        this->N = m2.N;
        data = new T * [M];
        for (int i = 0; i < M; i++)
            data[i] = new T[N];
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                data[i][j] = m2.data[i][j];
}

template <class T, T True, T False>
image< T, True, False>::~image() {
    if (N > 0){
        for (int i = 0; i < M; i++)
        delete[] data[i];
    }
    if (M > 0)
        delete[] data;
};

template <class T, T True, T False>
bool image< T, True, False>::GetMij(int i, int j) const {
    
    if (data == nullptr) throw "Image is empty";
    if ((i >= N) || (j >= M) || (i < 0) || (j < 0)) throw "Invalid index";
    return data[i][j];

}
template <class T, T True, T False>
void image< T, True, False>::SetMij(int i, int j, T value) const {
   
    if ((value == True) || (value == False))
    {
        if ((i < 0) || (i >= M))
            return;
        if ((j < 0) || (j >= N))
            return;
        data[i][j] = value;
    }
}
template <class T, T True, T False>
bool image< T, True, False>::can_multiply(const image& m2) {
    
    return ((M == m2.M) && (N == m2.N));
}
template <class T, T True, T False>
T image< T, True, False>::rand_() {
    bool temp = rand() % 2;
    if (temp) return (True); else return (False);
}
template <class T, T True, T False>
void image< T, True, False>::random() {
   
    if ((M == NULL) || (N == NULL)) throw "exeption";
    srand(time(0));
    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < cols(); j++) {
            T a = rand_();
            SetMij(i, j, a);           
        }
    }
}
template <class T, T True, T False>
image< T, True, False> image< T, True, False>:: operator+(const image& m2) {
    
    if (!(can_multiply(m2))) {
        throw ("The images are of different sizes, they can not be combined");
        image empty;
        return empty; 
    }
    else {
        image m3(M, N);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if ((data[i][j] == True) || (m2.data[i][j] == True))
                m3.data[i][j] = data[i][j] || m2.data[i][j];
            }
        }
        return m3;
    }
}
template <class T, T True, T False>
image< T, True, False> image< T, True, False>:: operator*(const image& m2) {
    
    if (!(can_multiply(m2))) {
        image empty;
        return empty;
    }
    else 
    {
        image m3(M, N);
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {                
                if ((data[i][j] == True) && (m2.data[i][j] == True))
                { 
                    m3.data[i][j] = (data[i][j] && m2.data[i][j]);
                }
            }
        }
        return m3;
    }
}
template <class T, T True, T False>
image< T, True, False> image< T, True, False>:: operator!() {
    
    image m3(M, N);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            m3.data[i][j] = !data[i][j];
        }
    }
    return m3;
}
template <class T, T True, T False>
image< T, True, False> image< T, True, False>::operator=(const image& m2) {
    
    image m3(m2);
    return m3;
}
template <class T, T True, T False>
image< T, True, False> image< T, True, False>:: operator*(bool value) {
   
    image m3(M, N);
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; j++) {
            m3.data[i][j] = data[i][j] && value;
        }
    }
    return m3;
}
template <class T, T True, T False>
image< T, True, False> image< T, True, False>:: operator+ (bool value) {
    
    image m3(M, N);
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; j++) {
            if ((value) || (data[i][j] == True)) m3.data[i][j] = data[i][j]||value;
        }
    
    }
    return m3;
}
template <class T, T True, T False>
bool image< T, True, False>::draw() {
    
    int a = M * N;
    int counter = 0;
    while (counter != a) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++)
            {
                double tmp;
                cout << "[" << i << "]" << "[" << j << "] = ";
                cin >> tmp;
                data[i][j]=(int)tmp;
                counter++;
            }
        }
    }
    return true;
}
template <class T, T True, T False>
void image< T, True, False>::print() { 
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (data[i][j] == True) {
                cout << "1" << " ";
            }
            else if (data[i][j] == False) {
                cout << "*" << " ";
            }
        }
        cout << endl;
    }
}
template <class T, T True, T False>
double image< T, True, False>::coefficient() {
    double a1 = 0;
    double all = M * N;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (data[i][j] == True)
                a1++;
        }
    }
    if (a1 == 0)
        return 0;
    else
    {
        return a1 / all;
    }
}
template <class T, T True, T False>
int image<T, True, False>::rows() const {
    if (M == NULL) throw "exeption";
    return M;
}
template <class T, T True, T False>
int  image<T, True, False>::cols() const {
    if (N == NULL) throw "exeption";
    return N;
}
