#include <iostream>

using namespace std;

#ifndef INPUT_H_
#define INPUT_H_

class Input {
public:
	SDL_Event event;
	string check_event();
};

#endif
