
#include <iostream>
#include <fstream>
#include <math.h>

class Base
{
private:
public:
    virtual void Display(const char* path) = 0;
};

class fileASCII : public Base
{
private:
public:
    void Display(const char* path) override
    {
        char* buff = new char[2];
        buff[1] = '\0';
        std::ifstream in(path);
        if (in.is_open())
        {
            while (!in.eof())
            {
                in.get(buff, 2);
                std::cout << buff;
            }
        }
        std::cout << '\n';
        delete[] buff;
        in.close();
    }
};
class fileBin : public Base
{
private:
    void transfer(char &trans)
    {
        int number = int(trans);
        char* bin = new char[9];
        bin[8] = '\0';
        for (int i = 0; i < 8; i++)
        {
            if (pow(2, 7 - i) <= number)
            {
                bin[i] = '1';
                number -= pow(2, 7 - i);
            }
            else
            {
                bin[i] = '0';
            }
        }
        std::cout << bin << ' ';
        delete[] bin;
    }
public:
    void Display(const char* path) override
    {
        char* buff = new char[2];
        buff[1] = '\0';
        std::ifstream in(path);
        while (!in.eof())
        {
            in.get(buff, 2);
            transfer(buff[0]);
        }
        std::cout << '\n';
        delete[] buff;
        in.close();
    }
};

int main()
{
    std::cout << "start\n";
    fileASCII test1;
    test1.Display("C:\\Users\\Admin\\source\\repos\\Homework_FileClass\\Homework_FileClass\\tester.txt");
    fileBin test2;
    test2.Display("C:\\Users\\Admin\\source\\repos\\Homework_FileClass\\Homework_FileClass\\tester.txt");
}
