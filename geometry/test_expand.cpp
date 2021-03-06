// expand algorithm test
#include <iostream>
#include <boost/geometry/geometry.hpp>
#include "box2.hpp"

using geom::box2;
using geom::make;
using geom::make_inverse;
using geom::expand;

int main(int argc, char * argv[])
{
	box2 b = make_inverse<box2>();
	expand(b, glm::vec2{0,0});
	expand(b, glm::vec2{1,2});
	expand(b, glm::vec2{5,4});
	expand(b, make<box2>(3,3, 5,5));

	std::cout << boost::geometry::dsv(b) << std::endl;

	return 0;
}
