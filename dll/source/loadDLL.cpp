// ExeUsingDLL.cpp
#include <iostream>
#include <windows.h>

typedef int (*MultiplyFunc)(int, int);
typedef bool (*NotGate)(bool);

int main()
{
    HMODULE hDLL = LoadLibraryA("testDLL.dll");
    HMODULE hDLL2 = LoadLibraryA("testDLL2.dll");
// 1st DLL
    if (hDLL != NULL)
    {
        MultiplyFunc multiply = (MultiplyFunc)GetProcAddress(hDLL, "Multiply");
        if (multiply != NULL)
        {
            int a, b;
            std::cout << "Enter first number: ";
            std::cin >> a;
            std::cout << "Enter second number: ";
            std::cin >> b;

            int result = multiply(a, b);
            std::cout << "Result of multiplication: " << result << std::endl;
        }
        else
        {
            std::cerr << "Failed to get function pointer." << std::endl;
        }

        FreeLibrary(hDLL);
    }
    else
    {
        std::cerr << "Failed to load DLL." << std::endl;
    }
// 2nd DLL
    if (hDLL2 != NULL)
    {
        NotGate noteGate = (NotGate)GetProcAddress(hDLL2, "NotGate");
        if (noteGate != NULL)
        {
            bool a;
            std::cout << "Enter True or False : ";
            std::cin >> a;

            int result = noteGate(a);
            std::cout << "Result of NotGate : " << result << std::endl;
        }
        else
        {
            std::cerr << "Failed to get function pointer 2 ." << std::endl;
        }

        FreeLibrary(hDLL2);
    }
    else
    {
        std::cerr << "Failed to load DLL2." << std::endl;
    }

    return 0;
}


// Compile and link with g++ -o loadDLL.exe loadDLL.cpp