#pragma once
#include <string>
#include <fstream>
#include <vector>

namespace csv {
	class Reader {
		std::vector<std::string> _toVector(std::string line);
		std::vector<std::string> _columns;
		std::ifstream* _file;
		bool _end{ false };
	public:
		Reader(std::string filename, bool parseColumns = false);
		~Reader();
		std::vector<std::string> next();
		void close();
		bool hasNext();
	};
}
