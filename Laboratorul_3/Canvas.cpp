#include "Canvas.h"
#include "cstdlib"
#include "iostream"

Canvas::Canvas(int width, int height) {
	this->inaltime = height;
	this->latime = width;
	this->suprafata = (char**)(calloc(inaltime, sizeof(char*)));
	if (this->suprafata != NULL) {
		for (int i = 0; i < inaltime; ++i)
			this->suprafata[i] = (char*)(calloc(latime + 1, sizeof(char)));
	}
}
void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	for (int i = x - ray; i <= x + ray; ++i)
		for (int j = y - ray; j <= y + ray; ++j) {
			int punct = (i - x) * (i - x) + (j - y) * (j - y);
			if (ray * (ray - 1) <= punct && punct <= ray * (ray + 1))
				this->suprafata[i][j] = ch;
		}
}
void Canvas::FillCircle(int x, int y, int ray, char ch) {
	for (int i = x - ray; i <= x + ray; ++i)
		for (int j = y - ray; j <= y + ray; ++j)
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
				this->suprafata[i][j] = ch;
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	for (int i = top; i <= bottom; ++i)
		this->suprafata[left][i] = ch, this->suprafata[right][i] = ch;
	for (int j = left; j <= right; ++j)
		this->suprafata[j][top] = ch, this->suprafata[j][bottom] = ch;
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	for (int i = top; i <= bottom; ++i)
		for (int j = left; j <= right; ++j)
			this->suprafata[j][i] = ch;
}
void Canvas::SetPoint(int x, int y, char ch) {
	this->suprafata[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
	int distanta_in_dreapta = 2 * (y2 - y1);
	int distanta_in_jos = 2 * (y2 - y1) - (x2 - x1);
	int coord_1 = x1, coord_2 = y1;
	while (coord_1 <= x2) {
		this->suprafata[coord_1][coord_2] = ch;
		distanta_in_jos = distanta_in_dreapta + distanta_in_jos;
		if (distanta_in_jos >= 0)
			distanta_in_jos = distanta_in_jos - 2 * (x2 - x1), ++coord_2;
		++coord_1;
	}
}
void Canvas::Print() {
	for (int i = 0; i < this->latime; ++i) {
		for (int j = 0; j < this->inaltime; ++j)
			std::cout << this->suprafata[i][j] << ' ';
		std::cout << '\n';
	}
}
void Canvas::Clear() {
	for (int i = 0; i < this->latime; ++i)
		for (int j = 0; j < this->inaltime; ++j)
			this->suprafata[i][j] = ' ';
}