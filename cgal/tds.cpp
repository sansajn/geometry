/* S dokumentacie

Triangulations and Delaunay Triangulations
	3D Triangulation Data Structure
	
	http://doc.cgal.org/latest/TDS_3/index.html#TDS_3IncrementalConstruction 
*/
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <CGAL/Triangulation_data_structure_3.h>

using Tds = CGAL::Triangulation_data_structure_3<>;
using size_type = Tds::size_type;
using Cell_handle = Tds::Cell_handle;
using Vertex_handle = Tds::Vertex_handle;

int main(int argc, char * argv[])
{
	Tds T;
	assert(T.number_of_vertices() == 0);
	assert(T.dimension() == -2);
	assert(T.is_valid());
	
	std::vector<Vertex_handle> PV(7);
	PV[0] = T.insert_increase_dimension();
	assert(T.number_of_vertices() == 1);
	assert(T.dimension() == -1);
	assert(T.is_valid());
	
	// each of the following insertions of vertices increases the dimension
	for (int i = 1; i < 5; ++i)
	{
		PV[i] = T.insert_increase_dimension(PV[0]);
		assert(T.number_of_vertices() == (size_type)i+1);
		assert(T.dimension() == i-1);
		assert(T.is_valid());
	}
	assert(T.number_of_cells() == 5);
	
	// we now have a simplex in dimension 4
	
	// cell incident to PV[0]
	Cell_handle c = PV[0]->cell();
	int ind;
	bool check = c->has_vertex(PV[0], ind);
	assert(check);
	// PV[0] is the vertex of index ind in c
	
	// insertion of a new vertex in the facet opposite to PV[0]
	PV[5] = T.insert_in_facet(c, ind);
	
	assert(T.number_of_vertices() == 6);
	assert(T.dimension() == 3);
	assert(T.is_valid());
	
	// insertion of a new vertex in c
	PV[6] = T.insert_in_cell(c);
	
	assert(T.number_of_vertices() == 7);
	assert(T.dimension() == 3);
	assert(T.is_valid());
	
	std::ofstream fout("output_tds", std::ios::out);
	fout << T;
	
	return 0;
}
