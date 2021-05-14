#include <iostream>

class my_vector
{
private:
    void assign(const my_vector& other, bool will_clean_up);
public:
    int n;
    int* p;
    my_vector(int n);
    my_vector(const my_vector& other);
    ~my_vector();
    my_vector& operator=(const my_vector& other);
    my_vector operator+(const my_vector& rhs);
    void display();
};
