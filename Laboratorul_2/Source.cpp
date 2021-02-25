#include "iostream"
#include "cstdlib"
#include "cstdio"
#include "NumberList.h"

int main(){
	NumberList obiect;
	obiect.Init();
	obiect.Add(10);
	obiect.Add(2);
	obiect.Add(7);
	obiect.Add(29);
	obiect.Print();
	obiect.Sort();
	obiect.Print();
}