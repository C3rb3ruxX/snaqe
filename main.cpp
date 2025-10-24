#include <iostream>
#include <thread>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;

const int TICKS_PER_SECOND = 16;

typedef char Matrix [WIDTH][HEIGHT];

struct vec2{
	int x;
	int y;
};

struct GameState{
	bool isRunning = false;

	/*
		La culebra
	*/
};

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

void tick(GameState &gameState){
	
}

int main(){

	GameState gameState;
	gameState.isRunning;

	Matrix table;
	initMatrix(table, '0');
	showMatrix(table);

	while(gameState.isRunning){

		tick(gameState);

		this_thread::sleep_for(chrono::milliseconds(1000/TICKS_PER_SECOND));
	}

	return 0;
}
