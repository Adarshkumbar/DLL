// MultiplicationDLL.cpp
// #include <iostream>

extern "C" __declspec(dllexport) int Multiply(int a, int b)
{
    return a * b;
}
