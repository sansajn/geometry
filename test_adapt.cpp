#include <boost/geometry/geometry.hpp>
#include "box2.hpp"

namespace geom = boost::geometry;

int main(int argc, char * argv[])
{
	box2 b = geom::make_inverse<box2>();

	return 0;
}
