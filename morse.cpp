#include <iostream>
#include <string>
#include <map>

using namespace std;

const string version = "0.1.3";

map<char, string> mcodes{
	{ 'a', ".-" },
	{ 'b', "-..." },
	{ 'c', "-.-." },
	{ 'd', "-.."} ,
	{ 'e', "." },
	{ 'f', "..-." },
	{ 'g', "--." },
	{ 'h', "...." },
	{ 'i', ".." },
	{ 'j', ".---" },
	{ 'k', "-.-" },
	{ 'l', ".-.." },
	{ 'm', "--" },
	{ 'n', "-." },
	{ 'o', "---" },
	{ 'p', ".--." },
	{ 'q', "--.-" },
	{ 'r', ".-." },
	{ 's', "..." },
	{ 't', "-" },
	{ 'u', "..-" },
	{ 'v', "...-" },
	{ 'w', ".--" },
	{ 'x', "-..-" },
	{ 'y', "-.--" },
	{ 'z', "--.." },
	{ '1', ".----" },
	{ '2', "..---" },
	{ '3', "...--" },
	{ '4', "....-" },
	{ '5', "....." },
	{ '6', "-...." },
	{ '7', "--..." },
	{ '8', "---.." },
	{ '9', "----." },
	{ '0', "-----" },
	{ '@', ".--.-." },
	{ '.', "--..--" },
	{ '-', "-....-" }
};

string get_code(char c) {
	return mcodes[c];
}

string encrypt(string msg) {
	string out = "";
	for (char const &c: msg) {
		out.append(get_code(tolower(c)) + " ");
	}
	return out;
}

int main(int argc, char* argv[]) {
	string function = string(argv[1]);
	if (function == "--encrypt" || function == "-e") {
		string out = "";
		for (int x = 2; argc > x; x++) {
			out.append(encrypt(argv[x]) + " / ");
		}
		cout << out.erase(out.size() - 3) << endl;
	} else if (function == "--decrypt" || function == "-d") {
		cout << "The Decryption Module is not implemented" << endl;
	} else if (function == "--version" || function == "-v") {
		cout << version << endl;
	} else {
		cout << "Nothing to do" << endl;
	}
	return 0;
}
