/*
 * Row.h
 *
 *  Created on: Jun 24, 2017
 *      Author: KP7
 */

#ifndef ROW_H_
#define ROW_H_

#include <algorithm>
#include <SDL.h>

class Row {
private:
	bool cell[10];
	SDL_Texture* color[10];

public:
	void set_cells(bool board_cell[10]);
	void set_color(SDL_Texture* board_color[10]);
	bool empty_full();
	bool check_empty();
	void set_board(bool board_cell[22][10], SDL_Texture* color[22][10], int count);
	bool check_any();
};

#endif /* ROW_H_ */
