#include <iostream>
#include <SDL.h>
#include "Input.h"
using namespace std;
string Input::check_event() {
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
			case SDLK_a:
				return "a_d";
			case SDLK_d:
				return "d_d";
			case SDLK_e:
				return "e_d";
			case SDLK_RETURN:
				return "return_d";
			}
		} else if (event.type == SDL_KEYUP) {
			switch (event.key.keysym.sym) {
			case SDLK_a:
				return "a_u";
			case SDLK_d:
				return "d_u";
			case SDLK_e:
				return "e_u";
			}
		} else if (event.type == SDL_QUIT) {
			return "quit";
		}
	}

	return "null";
}
