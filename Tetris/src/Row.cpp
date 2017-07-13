/*
 * Row.cpp
 *
 *  Created on: Jun 24, 2017
 *      Author: KP7
 */

#include "Row.h"
#include <iostream>

void Row::set_cells(bool board_cell[4]){

	for(int i = 0; i < 10; i++){
		cell[i] = board_cell[i];
	}



}

void Row::set_color(SDL_Texture* board_color[10]){

	for(int i = 0; i < 10; i++){
		color[i] = board_color[i];
	}
}

bool Row::empty_full(){

	if(cell[0] == true && cell[1] == true && cell[2] == true && cell[3] == true && cell[4] == true && cell[5] == true && cell[6] == true && cell[7] == true && cell[8] == true && cell[9] == true){
		for(int i = 0; i < 10; i++){
			cell[i] = false;
		}
		return true;
	}

	return false;


}

bool Row::check_empty(){
	if(cell[0] == false && cell[1] == false && cell[2] == false && cell[3] == false && cell[4] == false && cell[5] == false && cell[6] == false && cell[7] == false && cell[8] == false && cell[9] == false){
		return true;
	}
	return false;
}

void Row::set_board(bool board_cell[22][10], SDL_Texture* color[22][10], int count){
	for(int i = 0; i < 10; i++){
		board_cell[count][i] = cell[i];
		color[count][i] = this->color[i];
	}
}

bool Row::check_any(){
	if(cell[0] == true || cell[1] == true || cell[2] == true || cell[3] == true || cell[4] == true || cell[5] == true || cell[6] == true || cell[7] == true || cell[8] == true || cell[9] == true){
		return true;
	}
	return false;
}
