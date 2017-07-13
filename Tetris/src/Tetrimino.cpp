/*
 * Tetrimino.cpp
 *
 *  Created on: Jun 25, 2017
 *      Author: KP7
 */
#include <iostream>
#include "Tetrimino.h"

Tetrimino::Tetrimino() {

	int gen = rand() % 7 + 1; //Shape Generation
	if (gen == 1) {
		type = 'i';
		refx = 3;
	} else if (gen == 2) {
		type = 'l';
		refx = 5;
	} else if (gen == 3) {
		type = 'j';
		refx = 5;
	} else if (gen == 4) {
		type = 'o';
		refx = 5;
	} else if (gen == 5) {
		type = 's';
		refx = 5;
	} else if (gen == 6) {
		type = 'z';
		refx = 5;
	} else if (gen == 7) {
		type = 't';
		refx = 5;
	}

	refy = 1;
	pos = 0;
}

void Tetrimino::rotate() {
	pos += 1;
	if (pos == 4) {
		pos = 0;
	}

	if (pos == 0) {

		if (type == 'i') {
			refx -= 1;
			refy -= 1;
		}

	} else if (pos == 1) {
		if (type == 'i') {
			refx += 2;
			refy -= 2;
		}

	} else if (pos == 2) {
		if (type == 'i') {
			refx += 1;
			refy += 1;
		}

	} else if (pos == 3) {
		if (type == 'i') {
			refx -= 2;
			refy += 2;
		}
	}

}

void Tetrimino::move(char dir){
	if(dir == 'r'){
		refx++;
	}else if(dir == 'l'){
		refx--;
	}
}

void Tetrimino::move_down() {
	refy++;
}

int Tetrimino::return_refx() {
	return refx;
}
int Tetrimino::return_refy() {
	return refy;
}
int Tetrimino::return_pos() {
	return pos;
}
char Tetrimino::return_type() {
	return type;
}
