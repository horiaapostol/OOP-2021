#include "Canvas.h"

int main() {
	Canvas panza(20, 20);
	panza.DrawCircle(3, 3, 3, '*');
	panza.DrawRect(0, 8, 9, 16, '#');
	panza.Print();
	panza.Clear();
	panza.FillCircle(4, 4, 4, '*');
	panza.FillRect(0, 10, 12, 16, '#');
	panza.Print();
	panza.Clear();
	panza.SetPoint(2, 2, '$');
	panza.SetPoint(2, 5, 'x');
	panza.DrawLine(3, 3, 6, 6, '@');
	panza.Print();
}