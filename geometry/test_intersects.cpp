// testing intersects algorithm
#include <iostream>
#include <boost/geometry/geometry.hpp>
#include "box2.hpp"

using std::cout;
using glm::vec2;
namespace bg = boost::geometry;

int main(int argc, char * argv[]) {
	vec2 const pt = {.5,.5},
		min_corner = {0,0},
		max_corner = {1,1};

	geom::box2 const area = {min_corner, max_corner};

	if (bg::intersects(pt, area))
		cout << "intersects\n";
	else
		cout << "not intersects\n";

	return 0;
}
