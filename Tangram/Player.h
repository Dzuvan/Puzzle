#ifndef __Player__
#define __Player__
#include "GameObject.h"

class Player : public GameObject {
	void draw();
	void update();
	void clean();
};

#endif // !__Player__
