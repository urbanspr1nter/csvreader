#include <iostream>
#include "reader.h"

using namespace std;

int main() {
	int columnTitle = 0;
	int columnGenre = 1;

	csv::Reader reader{ "C:\\Users\\roger\\Desktop\\shows.csv" };
	vector<string> line{};
	while (reader.hasNext()) {
		line = reader.next();
		if (line.size() >= 2) {
			cout << line[columnTitle] << endl;
			cout << line[columnGenre] << endl;
		}
	}
	reader.close();
	return 0;
}