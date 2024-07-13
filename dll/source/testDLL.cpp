// MultiplicationDLL.cpp
// #include <iostream>

extern "C" __declspec(dllexport) int Multiply(int a, int b)
{
    return a * b;
}


// compile and link with g++ -shared -o testDLL.dll testDLL.cpp 