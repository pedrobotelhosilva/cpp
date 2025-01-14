#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <climits>
#include <cfloat>
#include <limits>
#include <cstdlib>
#include <cstring>
#include <cctype>

#define CHAR     1
#define INT      2
#define FLOAT    3
#define DOUBLE   4

class ScalarConverter
{
    private:
        std::string _input;
        ScalarConverter(ScalarConverter const & src);
        ScalarConverter &operator=(ScalarConverter const &ref);

    public:
        ScalarConverter(std::string input);

        std::string getInput(void) const;
        static bool checkNumber(std::string const s);
        static bool checkLetters(std::string const s);
        static bool checkLiteral(std::string const s, int type);
        static std::string to_string(double d);

        void printOutput(void);
        void printChar(void);
        void printInt(void);
        void printDouble(void);
        void printFloat(void);
        ~ScalarConverter(void);
};
