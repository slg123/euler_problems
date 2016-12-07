#include <iostream>

int a(int j) { std::cout << j++ << std::endl; return j; }
int b(int j) { return a(a(a(a(a(j))))); }
int c(int n) { return b(b(b(b(n)))); }

int main() { c(c(c(c(c(1))))); return 0; }

