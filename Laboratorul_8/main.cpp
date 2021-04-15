#include "fstream"
#include "iostream"
#include "string"
#include "algorithm"
#include "map"
#include "queue"

std::ifstream read("test.txt");

int main() {
	std::map < std::string, int > dictionar;
	std::string propozitie;
	std::getline(read, propozitie);
	std::transform(propozitie.begin(), propozitie.end(), propozitie.begin(), [](unsigned char c) { return std::tolower(c); });
	unsigned int inceput = propozitie.find_first_not_of(" ,?!.");
	while (inceput != std::string::npos) {
		unsigned int sfarsit = propozitie.find_first_of(" ,?!.", inceput + 1);
		std::string cuvant = propozitie.substr(inceput, sfarsit - inceput);
		dictionar[cuvant]++;
		inceput = propozitie.find_first_not_of(" ,?!.", sfarsit);
	}
	std::vector< std::pair<std::string, int>> Container;
	for (auto i = dictionar.begin(); i != dictionar.end(); ++i) {
		Container.push_back(std::make_pair(i->first, i->second));
	}
	auto Compare = [](std::pair<std::string, int>& a, std::pair<std::string, int>& b) {
		if (a.second == b.second) {
			return a.first > b.first;
		}
		return a.second < b.second;
	};
	std::priority_queue<std::pair<std::string, int>, std::vector< std::pair<std::string, int>>, decltype(Compare)> coada(Compare, Container);
	while (!coada.empty()) {
		std::cout << coada.top().first << " =>" <<coada.top().second << '\n';
		coada.pop();
	}
}