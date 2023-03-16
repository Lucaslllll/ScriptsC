#include <iostream>

#define BRANCO "\e[0m"
#define VERMELHO "\e[0;31m"
#define VERDE "\e[2;32m"
#define CIANO "\e[0;36m"
#define REDB "\e[41m"

using namespace std;

int main(int argc, char *argv[]){

	cout << BRANCO "A" << endl;
	cout << VERMELHO "B" << endl;
	cout << VERDE "C" << endl;
	cout << CIANO "D" << endl;
	cout << REDB "E" << endl;
	cout  << BRANCO  << endl;

}
