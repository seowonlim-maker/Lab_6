#include "book.h"
#include <array>

namespace Seowon2348078
{
    void printBookArray(const book a[], const int n)
    {
    for (int i=0; i < n; ++i)
        std::cout << a[i];
    std::cout << std::endl;
    }
}

int main()
{
    const int n{4};
    using namespace Seowon2348078;
    book a[n]; //book형 n개 있는 배열
    a[0]= book{"C++ programming", 1, 30000};
    a[1].setTitle("C programming"); a[1].setID(2); a[1].setPrice(20000);
    a[2].input();
    std::cin >> a[3];
    printBookArray(a, n);

    std::array<book, n> arr;
    for (int i=0; i < arr.size(); ++i)
        arr.at(i) = a[i]; //arr[i]=a[i];
    for (const auto& arri : arr)
        arri.print();

    return 0;
}