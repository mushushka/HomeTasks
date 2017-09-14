#include <iostream>
#include <sstream>


class Rational {

public:
    Rational() {}
    Rational (const int complete): _complete(complete){}
    Rational(const int complete, const int natural)
            : _complete(complete),
              _natural(natural)
    {
        if (_natural == 0) {

            //throw error
        }

        //нормализация
    }
    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);


private:

    int _complete {0};
    int _natural{1};
    ~Rational() = default;

//реализация нормализации






};





int main() {

    using namespace std;

   // Rational num = Rational(3,6);


    std::cout << "dfdfd" << std::endl;
    return 0;
}







