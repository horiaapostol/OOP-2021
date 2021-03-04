#include "Math.h"
#include "cstdarg"
#include "cstdlib"
#include "cstring"

int Math::Add(int a, int b) {
	return a + b;
}
int Math::Add(int a, int b , int c) {
	return a + b + c;
}
int Math::Add(double a, double b) {
	return a + b;
}
int Math::Add(double a, double b, double c) {
	return a + b + c;
}
int Math::Mul(int a, int b) {
	return a * b;
}
int Math::Mul(int a, int b, int c) {
	return a * b * c;
}
int Math::Mul(double a, double b) {
	return a * b;
}
int Math::Mul(double a, double b, double c) {
	return a * b * c;
}
int Math::Add(int count, ...) {
	int suma = 0;
	va_list lista;
	va_start(lista, count);
	for (int i = 0; i < count; ++i)
		suma += va_arg(lista, int);
	va_end(lista);
	return suma;
}
char* Math::Add(const char *a, const char *b) {
	size_t lungime = strlen(a) + strlen(b) + 1;
	char* p = (char *)malloc(lungime);
	memset(p, 0, lungime);
	memcpy(p, a, strlen(a));
	memcpy(p + strlen(a), b, strlen(b));
	return p;
}