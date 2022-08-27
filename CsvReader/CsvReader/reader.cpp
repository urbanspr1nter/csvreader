#include "reader.h"

csv::Reader::Reader(std::string filename, bool parseColumns) {
	this->_file = new std::ifstream();
	this->_file->open(filename);

	if (!this->_file->good()) {
		this->_file = nullptr;
		this->_end = true;
	}
	else {
		if (parseColumns) {
			this->_columns = this->next();
		}
	}
}

csv::Reader::~Reader() {
	this->_file->close();
}

std::vector<std::string> csv::Reader::next() {
	std::vector<std::string> result;

	if (this->_file == nullptr) {
		return result;
	}

	std::string line;
	std::getline(*this->_file, line);

	if (this->_file->eof()) {
		this->_end = true;
	}

	if (line.length() == 0) {
		return result;
	}

	return this->_toVector(line);
}

void csv::Reader::close() {
	this->_file->close();
}

bool csv::Reader::hasNext() {
	return !this->_end;
}

std::vector<std::string> csv::Reader::_toVector(std::string line) {
	std::vector<std::string> result;

	std::string word{ "" };
	bool inQuotes = false;

	for (size_t i = 0; i < line.length(); i++) {
		char c = line.at(i);

		if (c == '"') {
			inQuotes = !inQuotes;
		}
		else if (c == ',' && !inQuotes) {
			result.push_back(word);

			word = "";
		}
		else {
			word += c;
		}
	}

	result.push_back(word);

	return result;
}
