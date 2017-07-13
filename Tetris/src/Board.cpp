#include "Board.h"

std::vector<Row> row(22);

Board::Board(SDL_Renderer* renderer) {

	sur = IMG_Load("black.png");
	black_tex = SDL_CreateTextureFromSurface(renderer, sur);
	sur = IMG_Load("light_blue.png");
	light_blue_tex = SDL_CreateTextureFromSurface(renderer, sur);
	sur = IMG_Load("dark_blue.png");
	dark_blue_tex = SDL_CreateTextureFromSurface(renderer, sur);
	sur = IMG_Load("orange.png");
	orange_tex = SDL_CreateTextureFromSurface(renderer, sur);
	sur = IMG_Load("yellow.png");
	yellow_tex = SDL_CreateTextureFromSurface(renderer, sur);
	sur = IMG_Load("green.png");
	green_tex = SDL_CreateTextureFromSurface(renderer, sur);
	sur = IMG_Load("purple.png");
	purple_tex = SDL_CreateTextureFromSurface(renderer, sur);
	sur = IMG_Load("red.png");
	red_tex = SDL_CreateTextureFromSurface(renderer, sur);

	for (int i = 0; i < BOARD_HEIGHT; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {
			cell[i][j] = false;
		}
	}

	for (int i = 0; i < BOARD_HEIGHT; i++) {
		for (int j = 0; j < BOARD_WIDTH; j++) {
			block[i][j].x = BLOCK_DIM * j;
			block[i][j].y = BLOCK_DIM * i - (BLOCK_DIM * 2);
			block[i][j].w = BLOCK_DIM;
			block[i][j].h = BLOCK_DIM;
		}
	}

	for (int i = 0; i < 4; i++) {
		tetcellx[i] = 0;
		tetcelly[i] = 0;
		ptetcellx[i] = 0;
		ptetcelly[i] = 0;
	}

}
void Board::process_tetro(int refx, int refy, char type, int pos, int* x,
		int* y) {
	if (type == 'i') {
		if (pos == 0) {
			x[0] = refx;
			y[0] = refy;
			x[1] = refx + 1;
			y[1] = refy;
			x[2] = refx + 2;
			y[2] = refy;
			x[3] = refx + 3;
			y[3] = refy;
		} else if (pos == 1) {
			x[0] = refx;
			y[0] = refy;
			x[1] = refx;
			y[1] = refy + 1;
			x[2] = refx;
			y[2] = refy + 2;
			x[3] = refx;
			y[3] = refy + 3;
		} else if (pos == 2) {
			x[0] = refx;
			y[0] = refy;
			x[1] = refx - 1;
			y[1] = refy;
			x[2] = refx - 2;
			y[2] = refy;
			x[3] = refx - 3;
			y[3] = refy;
		} else if (pos == 3) {
			x[0] = refx;
			y[0] = refy;
			x[1] = refx;
			y[1] = refy - 1;
			x[2] = refx;
			y[2] = refy - 2;
			x[3] = refx;
			y[3] = refy - 3;
		}
	} else if (type == 'j') {
		if (pos == 0) {
			x[0] = refx;
			y[0] = refy;
			x[1] = refx + 1;
			y[1] = refy;
			x[2] = refx - 1;
			y[2] = refy;
			x[3] = refx - 1;
			y[3] = refy - 1;
		} else if (pos == 1) {
			x[0] = refx;
			y[0] = refy;
			x[1] = refx;
			y[1] = refy + 1;
			x[2] = refx;
			y[2] = refy - 1;
			x[3] = refx + 1;
			y[3] = refy - 1;
		} else if (pos == 2) {
			x[0] = refx;
			y[0] = refy;
			x[1] = refx - 1;
			y[1] = refy;
			x[2] = refx + 1;
			y[2] = refy;
			x[3] = refx + 1;
			y[3] = refy + 1;
		} else if (pos == 3) {
			x[0] = refx;
			y[0] = refy;
			x[1] = refx;
			y[1] = refy - 1;
			x[2] = refx;
			y[2] = refy + 1;
			x[3] = refx - 1;
			y[3] = refy + 1;
		}

	} else if (type == 'l') {
		if (pos == 0) {
			x[0] = refx;
			y[0] = refy;
			x[1] = refx - 1;
			y[1] = refy;
			x[2] = refx + 1;
			y[2] = refy;
			x[3] = refx + 1;
			y[3] = refy - 1;
		} else if (pos == 1) {
			x[0] = refx;
			y[0] = refy;
			x[1] = refx;
			y[1] = refy - 1;
			x[2] = refx;
			y[2] = refy + 1;
			x[3] = refx + 1;
			y[3] = refy + 1;
		} else if (pos == 2) {
			x[0] = refx;
			y[0] = refy;
			x[1] = refx + 1;
			y[1] = refy;
			x[2] = refx - 1;
			y[2] = refy;
			x[3] = refx - 1;
			y[3] = refy + 1;
		} else if (pos == 3) {
			x[0] = refx;
			y[0] = refy;
			x[1] = refx;
			y[1] = refy + 1;
			x[2] = refx;
			y[2] = refy - 1;
			x[3] = refx - 1;
			y[3] = refy - 1;
		}
	} else if (type == 'o') {
		x[0] = refx;
		y[0] = refy;
		x[1] = refx + 1;
		y[1] = refy;
		x[2] = refx;
		y[2] = refy + 1;
		x[3] = refx + 1;
		y[3] = refy + 1;
	} else if (type == 's') {
		if (pos == 0 || pos == 2) {
			x[0] = refx;
			y[0] = refy;
			x[1] = refx - 1;
			y[1] = refy;
			x[2] = refx;
			y[2] = refy - 1;
			x[3] = refx + 1;
			y[3] = refy - 1;
		} else if (pos == 1 || pos == 3) {
			x[0] = refx;
			y[0] = refy;
			x[1] = refx;
			y[1] = refy + 1;
			x[2] = refx - 1;
			y[2] = refy;
			x[3] = refx - 1;
			y[3] = refy - 1;
		}
	} else if (type == 'z') {
		if (pos == 0 || pos == 2) {
			x[0] = refx;
			y[0] = refy;
			x[1] = refx + 1;
			y[1] = refy;
			x[2] = refx;
			y[2] = refy - 1;
			x[3] = refx - 1;
			y[3] = refy - 1;
		} else if (pos == 1 || pos == 3) {
			x[0] = refx;
			y[0] = refy;
			x[1] = refx;
			y[1] = refy + 1;
			x[2] = refx + 1;
			y[2] = refy;
			x[3] = refx + 1;
			y[3] = refy - 1;
		}

	} else if (type == 't') {
		if (pos == 0) {
			x[0] = refx;
			y[0] = refy;
			x[1] = refx;
			y[1] = refy - 1;
			x[2] = refx + 1;
			y[2] = refy;
			x[3] = refx - 1;
			y[3] = refy;
		} else if (pos == 1) {
			x[0] = refx;
			y[0] = refy;
			x[1] = refx + 1;
			y[1] = refy;
			x[2] = refx;
			y[2] = refy + 1;
			x[3] = refx;
			y[3] = refy - 1;
		} else if (pos == 2) {
			x[0] = refx;
			y[0] = refy;
			x[1] = refx;
			y[1] = refy + 1;
			x[2] = refx - 1;
			y[2] = refy;
			x[3] = refx + 1;
			y[3] = refy;
		} else if (pos == 3) {
			x[0] = refx;
			y[0] = refy;
			x[1] = refx - 1;
			y[1] = refy;
			x[2] = refx;
			y[2] = refy - 1;
			x[3] = refx;
			y[3] = refy + 1;
		}
	}
}

void Board::copy_tetro(int refx, int refy, char type, int pos) { // Shove this shit into its own function that way we can use it for the predict rotation
	process_tetro(refx, refy, type, pos, tetcellx, tetcelly);
}

bool Board::can_rotate(int refx, int refy, char type, int pos) {

	pos++;
	if (pos == 4) {
		pos = 0;
	}
	process_tetro(refx, refy, type, pos, ptetcellx, ptetcelly);

	for (int i = 0; i < 4; i++) {
		if (cell[ptetcelly[0]][ptetcellx[0]] == true
				|| cell[ptetcelly[1]][ptetcellx[1]] == true
				|| cell[ptetcelly[2]][ptetcellx[2]] == true
				|| cell[ptetcelly[3]][ptetcellx[3]] == true || tetcellx[i] == 0
				|| tetcellx[i] == 9 || tetcelly[i] == 1 || tetcelly[i] == 21) {
			return false;
		}
	}
	return true;
}

bool Board::can_move(char dir) {
	if (dir == 'r') {
		for (int i = 0; i < 4; i++) {

			if (cell[tetcelly[i]][tetcellx[i] + 1] == true
					|| (cell[tetcelly[i] + 1][tetcellx[i] + 1] == true
							&& cell[tetcelly[0] + 1][tetcellx[0]] == false
							&& cell[tetcelly[1] + 1][tetcellx[1]] == false
							&& cell[tetcelly[2] + 1][tetcellx[2]] == false
							&& cell[tetcelly[3] + 1][tetcellx[3]] == false)
					|| tetcellx[i] == 9) {
				return false;
			}

		}

		return true;

	} else if (dir == 'l') {

		for (int i = 0; i < 4; i++) {

			if (cell[tetcelly[i]][tetcellx[i] - 1] == true
					|| (cell[tetcelly[i] + 1][tetcellx[i] - 1] == true
							&& cell[tetcelly[0] + 1][tetcellx[0]] == false
							&& cell[tetcelly[1] + 1][tetcellx[1]] == false
							&& cell[tetcelly[2] + 1][tetcellx[2]] == false
							&& cell[tetcelly[3] + 1][tetcellx[3]] == false)
					|| tetcellx[i] == 0) {

				return false;
			}
		}

		return true;
	}

	return true;
}

bool Board::touch_down() {
	for (int i = 0; i < 4; i++) {

		if (cell[tetcelly[i] + 1][tetcellx[i]] == true || tetcelly[i] == 21) {
			return true;
		}

	}
	return false;
}

void Board::update_tetrimino(SDL_Renderer* renderer, char type) { //This 'activates' the blocks are testcellx & y (1-4) with the texture of its shape
	for (int i = 0; i < 4; i++) {
		if (type == 'i') {
			SDL_RenderCopy(renderer, light_blue_tex, NULL,
					&block[tetcelly[i]][tetcellx[i]]);
		} else if (type == 'l') {
			SDL_RenderCopy(renderer, orange_tex, NULL,
					&block[tetcelly[i]][tetcellx[i]]);
		} else if (type == 'j') {
			SDL_RenderCopy(renderer, dark_blue_tex, NULL,
					&block[tetcelly[i]][tetcellx[i]]);
		} else if (type == 'o') {
			SDL_RenderCopy(renderer, yellow_tex, NULL,
					&block[tetcelly[i]][tetcellx[i]]);
		} else if (type == 's') {
			SDL_RenderCopy(renderer, green_tex, NULL,
					&block[tetcelly[i]][tetcellx[i]]);
		} else if (type == 'z') {
			SDL_RenderCopy(renderer, red_tex, NULL,
					&block[tetcelly[i]][tetcellx[i]]);
		} else if (type == 't') {
			SDL_RenderCopy(renderer, purple_tex, NULL,
					&block[tetcelly[i]][tetcellx[i]]);
		}

	}
}

void Board::clear_tetrimino(SDL_Renderer* renderer) {
	for (int i = 0; i < 4; i++) {
		SDL_RenderCopy(renderer, black_tex, NULL,
				&block[tetcelly[i]][tetcellx[i]]);
	}
}

void Board::update_cells() {
	cell[tetcelly[0]][tetcellx[0]] = true;
	cell[tetcelly[1]][tetcellx[1]] = true;
	cell[tetcelly[2]][tetcellx[2]] = true;
	cell[tetcelly[3]][tetcellx[3]] = true;
}

void Board::check_row() {

	bool row_cells[10];
	SDL_Texture* row_colors[10];

	for (int i = 0; i < 22; i++) {


		for (int j = 0; j < 10; j++) {
			row_cells[j] = cell[i][j];
			row_colors[j] = block_tex[i][j];
		}

		row[i].set_color(row_colors);
		row[i].set_cells(row_cells);
	}

	for (int i = 21; i > 0; i--) {
		if (row[i].empty_full() == true) {
			for (int j = i; j > 0; j--) {
				row[j] = row[j - 1];
			}
			i = 22;
		}
	}

	for (int i = 0; i < 22; i++) {
		row[i].set_board(cell, block_tex, i);
	}

	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 10; j++) {
			std::cout << cell[i][j] << std::flush;
		}
		std::cout << std::endl;
	}

}

void Board::clear_blocks(SDL_Renderer* renderer) {

	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 10; j++) {
			if (cell[i][j] == false) {
				block_tex[i][j] = black_tex;
			}
		}
	}

}

void Board::set_cell_color(char type) {
	if (type == 'i') {
		for (int i = 0; i < 4; i++) {
			block_tex[tetcelly[i]][tetcellx[i]] = light_blue_tex;
		}
	} else if (type == 'j') {
		for (int i = 0; i < 4; i++) {
			block_tex[tetcelly[i]][tetcellx[i]] = dark_blue_tex;
		}
	} else if (type == 'l') {
		for (int i = 0; i < 4; i++) {
			block_tex[tetcelly[i]][tetcellx[i]] = orange_tex;
		}
	} else if (type == 's') {
		for (int i = 0; i < 4; i++) {
			block_tex[tetcelly[i]][tetcellx[i]] = green_tex;
		}
	} else if (type == 'z') {
		for (int i = 0; i < 4; i++) {
			block_tex[tetcelly[i]][tetcellx[i]] = red_tex;
		}
	} else if (type == 'o') {
		for (int i = 0; i < 4; i++) {
			block_tex[tetcelly[i]][tetcellx[i]] = yellow_tex;
		}
	} else if (type == 't') {
		for (int i = 0; i < 4; i++) {
			block_tex[tetcelly[i]][tetcellx[i]] = purple_tex;
		}
	}
}

void Board::draw(SDL_Renderer* renderer){

	for(int i = 0; i < 22; i++){
		for(int j = 0; j < 10; j++){
			SDL_RenderCopy(renderer, block_tex[i][j], NULL, &block[i][j]);
		}
	}


}

bool Board::check_loss(){
	if(row[1].check_any() == true){
		return true;
	}
	return false;
}
