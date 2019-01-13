# geometry
Implmentuje geometricke algoritmy štruktúry a pomocné funkcie. 


## geometry:inštalácia

pod ubuntu 18.04

libglm-dev (0.9.9)




geometrické primitívy ?

point, line, ... ?

## geometry:štruktúra

**boost_geometry_adapt.hpp** : Algoritmi s knižnice `boost::geometry`.

**box2.hpp** : Implementácia modelu obdlžníka.

**box3.hpp** : Implementácia modelu kvádra.

**utility.hpp** : Funkcie pracujúce s rotáciou.

**glmprint.hpp** : Formátovaný výstup.

```c++
mat4 M{1};
cout << with_label("M", M);
```

## geometry:ukážky

```c++
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
```

