#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>



void mudar(int &x, int&y){
	x = 10;
	y = 20;

}


int main(int argc, char *argv[]){
	int x = 2;
	int y = 4;
	char m;

	std::cin >> m;

	if (m == 's'){
		mudar(x, y);
	}
	

	std::cout << "X: " <<  x << "Y: " << y << "\n";


	return 0;
}