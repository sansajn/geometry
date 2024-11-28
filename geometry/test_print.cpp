#include <string>
#include <iostream>
#include <glm/matrix.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include "glmprint.hpp"

using std::string;
using std::cout;
using glm::mat4, glm::mat3;
using glm::vec2, glm::vec3, glm::vec4;

int main(int argc, char * argv[]) {
	mat4 const M = mat4{
		11, 21, 31, 41,  // column 1
		12, 22, 32, 42,
		13, 23, 33, 43,
		14, 24, 34, 44};

	cout << "stream unnamed matrix prints:\n";
	cout << "M=" << M << '\n';

	cout << '\n';


	cout << "stream based matrix prints:\n";
	cout << with_label{"M", M};

	mat3 M3 = mat3{M};
	cout << with_label{"M3", M3};

	cout << '\n';

	cout << "stream unnamed vector prints:\n"
		<< "v2=" << vec2{1,2} << '\n'
		<< "v3=" << vec3{1,2,3} << '\n'
		<< "v4=" << vec4{1,2,3,4} << '\n';

	cout << '\n';

	cout << "named function based prints:\n";
	print_vector(vec4{1,2,3,4}, "v4");

	cout << "done!\n";

	return 0;
}
