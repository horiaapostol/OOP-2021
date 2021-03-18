#include "Number.h"
#include "cstdio"
#include "iostream"
#include "cassert"

namespace Example {
	int main()
	{
		Number n1("10110010", 2);
		Number n2("734", 8);
		Number n3("FF", 16);
		printf("n1 has %d digits and it is written in base %d\n", n1.GetDigitsCount(), n1.GetBase());
		for (int tr = 0; tr < n1.GetDigitsCount(); tr++)
		{
			printf("n1[%d]=%c\n", tr, n1[tr]);
		}
		n1.Print();
		n2.Print();
		n1 = (n2 + n3 - n1) + n1; // after this n1 will be in base 16
		n1.SwitchBase(2);
		n1.Print();
		if (n1 > n2) printf("n1 is bigger than n2\n"); else printf("n2 is bigger than n1\n");
		Number n4 = 12345; // n4 will be in base 10
		n1 = 255; // n1 will be 11111111 (value 255 from base 10 in base 2)
		n4 += n1;
		n4.Print();
		n4 = "13579"; // n4 mentains its base (10) and will be 13579
		n4.Print();
		--n4; // the first digit from n4 will be remove ==> n4 becomes 3579
		n4.Print();
		n4--; // the last digit from n4 will be remove ==> n4 becomes 357
		n4.Print();
		return 0;
	}
}

void run_all_tests() {
	Number n("25", 10);
	assert(n.GetBase() == 10);
	assert(n.GetDigitsCount() == 2);

	Number a("1111", 2);
	assert(a.GetBase() == 2);
	assert(a.GetDigitsCount() == 4);

	n = a + n;
	assert(n.GetBase() == 10);
	assert(n.GetDigitsCount() == 2);

	a = n;
	Number b("40", 10);
	Number c("45", 10);
	Number d("35", 10);

	assert(a == b);
	assert(a != c);
	assert(a >= b);
	assert(a <= b);
	assert(a <= c);
	assert(a >= d);
	assert(a < c);
	assert(a > d);
	
	Number n1("11", 2);
	Number n2("4", 10);
	Number n3("15", 6);

	n3.SwitchBase(10);
	n3 = 10;
	n3 = "0";

	n1 -= n2;
	n3 += n1;

	Number n4("0", 10);
	n4 = -1;
	assert(n3 == n4);

	Number a1("12423", 10);
	assert(a1[0] == '1');
	assert(a1[4] == '3');
	--a1;
	a1--;
	assert(a1 == 242);
}
int main() {
	Example::main();
	run_all_tests();
	Number a("-A", 16);
	Number b("-1010", 2);
	std::cout << "\nExceptii:\n";
	a.Print();
	b.Print();
	!b;
	b.Print();
	!b;
	assert(a == b);
	a = a + b;
	a.SwitchBase(1);
	a.SwitchBase(25);
	a.SwitchBase(7);
	a.SwitchBase(10);
	a.Print();
	std::cout << b[0] << '\n';
	std::cout << b[1] << '\n';
	std::cout << b[2] << '\n';
	std::cout << b[3] << '\n';
	std::cout << b[4] << '\n';

	b = 15;
	b.Print();

	b = "123";
	
	Number c = 100;
	std::cout << c.GetBase();
	c.SwitchBase(16);

	assert(c == 0x64);
}