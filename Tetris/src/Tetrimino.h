
#ifndef TETRIMINO_H_
#define TETRIMINO_H_

#include <string>
#include <stdlib.h>

class Tetrimino {
private:
	char type; // I, L, J, O, S, J, T
	int refx, refy;
	int pos;
public:
	Tetrimino();

	void rotate();
	void move_down();
	void move(char dir);

	int return_refx();
	int return_refy();
	int return_pos();
	char return_type();
};

#endif
