#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "SDL_image.h"
#include "Input.h"
#include "Board.h"
#include "Tetrimino.h"

void draw(SDL_Renderer* renderer, SDL_Window* window) {
	SDL_RenderPresent(renderer);
	SDL_UpdateWindowSurface(window);

}

int main(int argc, char* argv[]) {

	srand(time(NULL));

	const int WIN_HEIGHT = 700;
	const int WIN_WIDTH = 350;
	const int MS = 16;

	//Screen initializers
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL init error: %s\n", SDL_GetError());
	}

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		printf("SDL init error: %s\n", IMG_GetError());
	}

	SDL_Window* window;
	SDL_Renderer* renderer;

	window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	//Gamestate & stuff
	int gamestate = 0;
	int down_timer;

	//Bools
	bool a = false;
	bool d = false;
	bool e = false;

	bool on_floor = false;

	//Classes
	Tetrimino* tetrimino = new Tetrimino;
	Board board(renderer);
	Input input;

	//Clock stuff
	unsigned int last = SDL_GetTicks();
	unsigned int lag = 0;
	unsigned int speed = 160;

	while (true) {
		unsigned int current = SDL_GetTicks(); //Clock
		unsigned int elapsed = current - last;
		last = current;
		lag += elapsed;

		if (gamestate == 0) { //Freefall phase.

			if (lag >= 1600) {

				string event = input.check_event();

				if (event == "a_d") {
					a = true;
				} else if (event == "d_d") {
					d = true;
				} else if (event == "e_d") {
					e = true;
				} else if (event == "a_u") {
					a = false;
				} else if (event == "d_u") {
					d = false;
				} else if (event == "e_u") {
					e = false;
				} else if (event == "quit") {
					gamestate = 2;
				}

				if (on_floor == false) {
					tetrimino->move_down();
				}

				if (a == true) {
					if (board.can_move('l') == true) {
						tetrimino->move('l');
					}
				}

				if (d == true) {
					if (board.can_move('r') == true) {
						tetrimino->move('r');
					}
				}

				if (e == true) {
					if (board.can_rotate(tetrimino->return_refx(),
							tetrimino->return_refy(), tetrimino->return_type(),
							tetrimino->return_pos()) == true) {
						tetrimino->rotate();
					}
				}

				board.copy_tetro(tetrimino->return_refx(),
						tetrimino->return_refy(), tetrimino->return_type(),
						tetrimino->return_pos());

				if (board.touch_down() == true) {
					on_floor = true;
					down_timer++;
				} else if (board.touch_down() == false) {
					on_floor = false;
					down_timer = 0;
				}

				if (on_floor == true && down_timer >= 5) {
					down_timer = 0;
					gamestate = 1;
				}

				board.update_tetrimino(renderer, tetrimino->return_type());
				draw(renderer, window);
				board.clear_tetrimino(renderer);

				lag -= 160;
			}

		} else if (gamestate == 1) { //Touchdown phase.
			board.clear_tetrimino(renderer);
			board.update_cells();
			board.set_cell_color(tetrimino->return_type());
			delete tetrimino;
			Tetrimino* tetrimino = new Tetrimino;
			on_floor = false;

			board.check_row();

			board.clear_blocks(renderer);
			board.draw(renderer);
			draw(renderer, window);

			if (board.check_loss() == true) {
				gamestate = 2;
			}else{
				gamestate = 0;
			}
		} else if (gamestate == 2) {
			break;
		}

	}

	return 0;
}
