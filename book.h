#pragma once
#include <iostream> 

namespace Seowon2348078
{
    class book
    {
    // private: <default, no need
        int id; //id: 1~1000
        int price; //price: 0~50000 won
        void testID()
        {
            if ((id < 1) || (id > 1000)) {
                std::cout << "Illegal ID value! \n";
                std::exit(1);
            }

        }
        void testPrice()
        {
            if ((price < 0) || (price > 50000)) {
                std::cout << "Illegal price value! \n";
                std::exit(1);
            }
        }
    public:

      book(int d = 1, int p = 0):id{d}, price{p}
      {
        testID(); testPrice();
      }

        void input() //book b; b.input();
        {
            std::cout << "Enter the book id: ";
            std::cin >> id; testID();
            std::cout << "Enter the book price: ";
            std::cin >> price; testPrice();
        }
         friend std::istream& operator>>(std::istream& is, book& b) 
        {//book b; std::cout << "Enter book id, price: "; std::cin >> b;
           // is >> b.id >> b.price; b.testID(); b.testPrice();
            //book b; std::cin >> b;
            std::cout << "Enter the book id: ";
            is >> b.id; b.testID();
            std::cout << "Enter the book price: ";
            is >> b.price; b.testPrice();
            return is;
        }
        void setID (int d) { id= d; testID();}
        void setPrice (int p) { price= p; testPrice();}
        void print() const
        {
            std::cout << id << ", " << price << "won\n";
        }
        friend std::ostream& operator<<(std::ostream& os, const book& b)
        {
            os << b.id << "," << b.price << "won\n";
            return os;
        }

        int getID() const {return id;}
        int getPrice() const {return price;}

        book operator++(){return book{id, ++price};} //price만 증가
        book operator++(int){
            book temp{id, price};
            price++;
            return temp;
            //return book{id, price++}; 위 세줄이랑 동일
            }
    
        friend bool operator ==(const book& b1, const book& b2)
        {
            return b1.id == b2.id && b1.price == b2.price;
        }
        friend int operator +(const book& b1, const book& b2) //book은 2개 더하지만 return은 1개만 해서.. 원래 book 객체로 리턴하기 이상 >> int 
        {
            return b1.price + b2.price; 
        }
    };
}
// 1. 본인이름학번의 네임스페이스
// -본인이름학번 네임스페이스 예: 이름이 김프로이고 학번이 1234567일 경우 KimPro1234567
// using 지시자는 cpp파일에서는 영역 { block } 안에서 사용, 헤더파일엔 using 지시자는 사용하지 않고 네임스페이스 지정자를 사용합니다.
// -using 지시자 예: { using namespace std; cout << "Enter your id: "; }
// -네임스페이스 지정자 예: std::cout << "Enter your id: ";

// 2. 클래스명.h: 클래스 정의
// 1의 본인이름학번의 네임스페이스 안에 클래스를 정의하고 멤버함수들도 모두 인라인으로 구현합니다. 
// private 멤버변수 선언 (2개 이상)
// private 멤버함수 정의
// -test멤버변수1: 멤버변수1 범위가 아니면 프로그램 종료
// -test멤버변수2: 멤버변수2 범위가 아니면 프로그램 종료
// public 멤버함수 정의est함수들 호출
// -set 접근함수들: 멤버변수 값 설정 및 test함수 호출
// -print: 표준스트림출력으로 멤버변수들 출력
// -get 접근함수들: 멤버변수 값 리턴
// -input: 표준스트림입력으로 멤버변수들 입력, t

// -멤버함수로 전위증가연산자, 후위증가연산자 정의
// -프렌드함수로서 입력연산자 >>, 출력연산자 <<, 이항연산자 ==, 이항연산자 + 정의