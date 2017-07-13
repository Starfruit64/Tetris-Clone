

#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <SDL.h>
#include <algorithm>
#include "SDL_image.h"
#include <vector>
#include "Row.h"

class Board {
private:
	//Visuals
	const int WIN_HEIGHT = 700;
	const int WIN_WIDTH = 350;

	SDL_Texture* light_blue_tex;
	SDL_Texture* dark_blue_tex;
	SDL_Texture* orange_tex;
	SDL_Texture* yellow_tex;
	SDL_Texture* green_tex;
	SDL_Texture* purple_tex;
	SDL_Texture* red_tex;
	SDL_Texture* black_tex;

	SDL_Texture* block_tex[22][10];

	SDL_Surface* sur;
	SDL_Rect block[22][10]; //Only visual, so dont need the 20 blocks above the window
	int BLOCK_DIM = 35;

	//Logic
	int BOARD_HEIGHT = 23;
	int BOARD_WIDTH = 10;
	bool cell[22][10];
	const int ROW_COUNT = 22;

	int ptetcellx[4];//Predicted cells.
	int ptetcelly[4];
	int tetcellx[4];
	int tetcelly[4];






public:
	Board(SDL_Renderer* renderer);

	//Visuals
	void draw(SDL_Renderer* renderer);
	void update_tetrimino(SDL_Renderer* renderer, char type);
	void clear_tetrimino(SDL_Renderer* renderer);
	void clear_blocks(SDL_Renderer* renderer);
	void set_cell_color(char type);

	//Logic
	void process_tetro(int refx, int refy, char type, int pos, int* x, int* y);
	void update_cells();
	void copy_tetro(int refx, int refy, char type, int pos);
	void check_row();
	bool can_rotate(int refx, int refy, char type, int pos);
	bool can_move(char dir);
	bool touch_down();
	bool check_loss();

};

#endif
