// vygeneruje gulu (ako surface mesh)
#include <CGAL/Surface_mesh_default_triangulation_3.h>
#include <CGAL/Complex_2_in_triangulation_3.h>
#include <CGAL/make_surface_mesh.h>  // TODO: tento header bude asi stacit
#include <CGAL/Implicit_surface_3.h>

using Tr = CGAL::Surface_mesh_default_triangulation_3;  // triangulation for surface mesher
using C2t3 = CGAL::Complex_2_in_triangulation_3<Tr>;
using GT = Tr::Geom_traits;
using Sphere_3 = GT::Sphere_3;
using Point_3 = GT::Point_3;
using FT = GT::FT;

typedef FT (* Function)(Point_3);

using Surface_3 = CGAL::Implicit_surface_3<GT, Function>;

FT sphere_function(Point_3 p)
{
	FT const x2 = p.x()*p.x(), y2 = p.y()*p.y(), z2 = p.z()*p.z();
	return x2+y2+z2-1;
}

int main(int argc, char * argv[])
{
	Tr tr;  // 3d-delaunay triangulation
	C2t3 c2t3{tr};  // 2d-complex in 3d-delaunay triangulation

	// defining the surface
	Surface_3 surface{
		sphere_function,  // surface function (zero level set of a function)
		Sphere_3{CGAL::ORIGIN, 2.0}};  // bounding sphere

	// definig meshing criteria
	CGAL::Surface_mesh_default_criteria_3<Tr> criteria{
		30.0,  // angular bound
		0.1,   // radius bound
		0.1};  // distance bound

	// meshing surface
	CGAL::make_surface_mesh(c2t3, surface, criteria, CGAL::Non_manifold_tag{});

	std::cout << "final number of points: " << tr.number_of_vertices() << "\n";

	return 0;
}
