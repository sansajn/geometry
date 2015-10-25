// test bazovych vektorov rotacie
#include <iostream>
#include "utility.hpp"
#include "glmprint.hpp"

using std::cout;
using namespace glm;

int main(int argc, char * argv[])
{
	quat r = angleAxis(radians(90.0f), vec3{0,0,1});  // 90 deg okolo z
	cout << "right: " << geom::right(r) << "\n";
	cout << "up: " << geom::up(r) << "\n";
	cout << "forward: " << geom::forward(r) << "\n";
	return 0;
}
