#include <iostream>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;

typedef char Matrix [WIDTH][HEIGHT];

void initMatrix(Matrix &m, char a){
	int i, j;

	for (i=0; i < WIDTH; i++){
		for (j=0; j < HEIGHT; j++){
	
			m[i][j] = a;
		}
	}
}

void showMatrix(Matrix m){
	int i, j;

	//i 0..19
	for (i=0; i < HEIGHT; i++){
		//j 0..19
		for (j=0; j < WIDTH; j++){
			cout << m[i][j] << ' ';
		}
		cout<<endl;

	}
}

int main(){
	Matrix table;
	initMatrix(table, '0');
	showMatrix(table);
	cout << "Hola" << endl;
	return 0;
}
