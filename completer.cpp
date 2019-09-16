#include <fstream>
#include <iostream>
#include <algorithm>
#include "search.h"
#include <string>

using namespace std;
//Displays instructions
void info() {
	cout << "Search for strings by partial match.\n" << "Type C-z to halt." << endl;
}
//Function for getting user input for Yes/No
void decFunc(string &decision, string &word) {
	if (decision == "y" || decision == "Y" || decision == "Yes" || decision == "YES" || decision == "yes") {
		cout << "ok: accepting " << word << "\n";
	}
	else if (decision == "n" || decision == "N" || decision == "No" || decision == "NO" || decision == "no") {
		cout << "ok: rejecting " << word << "\n";
	}
}
//Function for reading the file and copying words into the vector
void readWords(ifstream &in,string &file,std::vector<string> &storage) {
	in.open(file);
	while (in.good())
	{
		std::string line;
		getline(in, line);
		std::transform(line.begin(), line.end(), line.begin(), ::tolower);
		storage.push_back(line);
	}
}

int main(int argc, char *argv[])
{
	string file;
	string rword;
	bool check = true;
	std::vector<std::string>  arguments;
	for (int i = 0; i < argc; ++i) arguments.push_back(argv[i]);
	
	file =argv[1] ;
	ifstream in;

	std::vector<string> myVec;
	
	readWords(in,file, myVec);

	while (check==true) {

		info();
		cin >> rword;
		if (cin.eof()) {
			break;
		}
		SearchResultType<string> result=iterative_binary_search(myVec, rword);
		if (result.found == true) {
			cout << "found: accepting " << rword << "\n";
		}
		else if (result.found == false) {
			cout << "Not found: accept " << result.value << "? Y/N: ";
			string decision;
			cin >> decision;
			decFunc(decision, result.value);
		}
	}

	return 0;
}

