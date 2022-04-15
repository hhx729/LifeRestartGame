#pragma once
#include<fstream>
#include<vector>
#include<cstring>
#include <sstream>
using namespace std;



class CsvFile {
public:
	CsvFile();
	~CsvFile();
	void ReadCsv(const string filename, vector<vector<string>>& store_to_array);
};

