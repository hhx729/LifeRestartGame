#include"csv_file.h"
using namespace std;



CsvFile::CsvFile() {}
CsvFile::~CsvFile() {}

void CsvFile::ReadCsv(const string filename, vector<vector<string>>& store_to_array) {
	ifstream inFile;
	inFile.open(filename, ios::in);
	string str_line;
	while (getline(inFile, str_line)) {
		stringstream str_stream(str_line);
		string cur_str;
		vector<string>lineArray;
		if (filename == "./age.csv") {
			while (getline(str_stream, cur_str, ',')) {
				if (cur_str != "")
					lineArray.push_back(cur_str);
			}
		}
		else {
			while (getline(str_stream, cur_str, ',')) {
				lineArray.push_back(cur_str);
			}
		}
		store_to_array.push_back(lineArray);
	}
	inFile.close();
}

