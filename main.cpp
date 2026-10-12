#include "book.h"

namespace Seowon2348078
{
    void printBookArray(const book a[], const int n)
    {
    for (int i=0; i < n; ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    }
}

int main()
{
    const int n{4};
    using namespace Seowon2348078;
    book a[n]; //book형 n개 있는 배열
    a[0]= book{"C++ programming", 1, 30000};
    a[0].print();

    a[1];
    a[2];
    a[3];

    return 0;
}