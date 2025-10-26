/**
 * Naming conventions:
 *		Constants:	Uppercase and underscores:										THIS_IS_A_CONSTANT;
 *		Variables:	Lowercase and underscores:										this_is_a_variable;
 *		Methods:		First lowercase and next words intials uppercased:		exampleMethod();
 *		Objects:		First initals uppercased:										ExampleObject{};
 */

#include <iostream>
#include <thread>

using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;

typedef char Matrix [WIDTH][HEIGHT];

struct vec2{
	int x;
	int y;
};

struct GameState{
	bool is_running = false;
	//Default value 16tps
	int ticks_per_second = 16;

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

void tick(GameState &game_state){
	
}

int main(){

	GameState game_state;
	game_state.is_running= true;

	Matrix table;
	initMatrix(table, '0');
	showMatrix(table);

	while(game_state.is_running){

		tick(game_state);
		this_thread::sleep_for(chrono::milliseconds(1000/game_state.ticks_per_second));

	}

	return 0;
}
