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

struct vec2{
	int x;
	int y;
};

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
			cout << (int)m[i][j] << ' ';
		}
		cout<<endl;

	}
}

//POST={The method substracts 1 for all natural numbers on the table >= 1}
void matrixNaturalsMinusOne(Matrix & m){
	int i, j;

	for (i=0; i < HEIGHT; i++){
		for (j=0; j < WIDTH; j++){
			if(m[i][j] >= 1){
				m[i][j] -= 1;
			}
		}
	}
}

enum SnakeDirection{
	UP		=0x01, 
	DOWN	=0x02, 
	LEFT	=0x04, 
	RIGHT =0x08
};

struct GameState{
	bool is_running = false;
	//Default value 16tps
	int ticks_per_second = 16;

	Matrix table;
	
	/*
		La culebra
	*/
	vec2 head_position = vec2{};
	SnakeDirection snake_direction = DOWN;
	char snake_length = 1;
};


/**
 * ===============
 * Snake functions
 * ===============
 */
void moveSnake(GameState &game_state){

	matrixNaturalsMinusOne(game_state.table);
	
	//Generate the head in the next position
	vec2 new_head_position = game_state.head_position;

	//TODO Boundary check
	switch(game_state.snake_direction){
		case UP:
			new_head_position.y--;
			break;
		case DOWN:
			new_head_position.y++;
			break;
		case LEFT:
			new_head_position.x--;
			break;
		case RIGHT:
			new_head_position.x++;
			break;
	}

	if(new_head_position.x < 0){
		new_head_position.x = WIDTH-1;
	}
	if(new_head_position.x >= WIDTH){
		new_head_position.x = 0;
	}
	if(new_head_position.y < 0){
		new_head_position.y = HEIGHT-1;
	}
	if(new_head_position.y >= HEIGHT){
		new_head_position.y = 0;
	}

	game_state.head_position = new_head_position;

	game_state.table[game_state.head_position.x][game_state.head_position.y] = game_state.snake_length;

}

/**
 * ====================
 * Game Logic Functions
 * ====================
 */

void tick(GameState &game_state){
	moveSnake(game_state);

	showMatrix(game_state.table);
	cout << endl;
}

int main(){

	GameState game_state;
	game_state.is_running = true;
	game_state.ticks_per_second = 3;

	game_state.snake_length = 4;

	initMatrix(game_state.table, 0);

	//Generate the snake in the center of the table
	game_state.head_position = vec2{
		.x = WIDTH/2,
		.y = HEIGHT/2
	};

	while(game_state.is_running){

		tick(game_state);
		this_thread::sleep_for(chrono::milliseconds(1000/game_state.ticks_per_second));

	}

	return 0;
}
