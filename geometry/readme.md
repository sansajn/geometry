# geometry
Boost.Geometry adaption for vector types (vec2, vec3 and vec4) from GLM library.

Thanks to Boost.Geometry we can construct geometric objects from vector types and use geometry algorithms e.g.

```cpp
vec2 pt = {1,1};
box2 b2 = {vec2{0,0}, vec2{1,1};
boost::geometry::intersects(pt, b2);  //= true
```

> TODO: What we have there? How to use stafff we have there?

- `utility.hpp`
- `box2.hpp`
- `box3.hpp`
- `glmprint.hpp`
- `boost_geometry_adapt.hpp`

> TODO: I rememer that I've renamed this to `glm_adapt.hpp`, but

## install

Nainštaluj nasledujúce balíčky

* libglm-dev (0.9.9, ubuntu 18.04)

príkazom `$ sudo apt install libglm-dev`


## geometry:štruktúra

**box2.hpp** : Implement rectangle (two dimensional box) model.

```c++
box2 b = make_inverse<box2>();  // TODO: what does this does?
expand(b, vec2{3,3});
expand(b, vec2{5,5});
box2 c = make<box2>(3,3, 5,5);
// b == c
```

To create box2 we can
```cpp
using boost::geometry::make;

box2 b;  // default constructed
box2 c{vec2{0,0}, vec2{1,1}};  // via constructor
box2 d = make<box2>(0,0, 1,1);  // via make function
```

> TODO: How to get width/height?
> TODO: How to get SW (min corner)?
> TODO: How to work with box2?

To access box corner points and width or height we can use `get`, `width` and `height` functions

```cpp
#include <boost/geometry/core/access.hpp>
namespace bg = boost::geometry;

box2 d = make<box2>(0,0, 1,1);

vec2 min_point = b.min_corner(),  // access corner points
	max_point = b.max_corner();
```


**box3.hpp** : implementácia modelu kvádra

```c++
box3 b = make<box3>(0,0,0, 1,1,1);
```

**utility.hpp** : funkcie pracujúce s rotáciou

```c++
quat r = angleAxis(radians(60.0f), vec3{0,0,1});
cout << "right=" << right(r) << "\n"
	<< "up=" << up(r) << "\n"
	<< "forward=" << forward(r) << "\n";
```

**glmprint.hpp** : formátovaný výstup

```c++
mat4 M{1};
cout << with_label("M", M);
```

**boost_geometry_adapt.hpp** : algoritmy s knižnice `boost::geometry`


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

int main(int argc, char * argv[]) {
	box2 b = make_inverse<box2>();
	expand(b, glm::vec2{0,0});
	expand(b, glm::vec2{1,2});
	expand(b, glm::vec2{5,4});
	expand(b, make<box2>(3,3, 5,5));

	std::cout << boost::geometry::dsv(b) << std::endl;

	return 0;
}
```
