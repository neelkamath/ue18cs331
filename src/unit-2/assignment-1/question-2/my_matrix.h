#include <iostream>

class my_matrix
{
private:
    void assign(const my_matrix& other, bool will_clean_up);
public:
    int m;
    int n;
    int* p;
    my_matrix(int m, int n);
    my_matrix(const my_matrix& other);
    ~my_matrix();
    my_matrix& operator=(const my_matrix& other);
    my_matrix operator+(const my_matrix& rhs);
    void display();
};
