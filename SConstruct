env = Environment(
	CXXFLAGS=['-std=c++11', '-g', '-O0', '-Wall', '-Wno-sign-compare'],
	CPPPATH=['.', 'libs'],
	LIBS=['glut', 'pthread', 'boost_system', 'boost_filesystem'],
	CPPDEFINES=['GLM_FORCE_RADIANS'])

env.ParseConfig('pkg-config --cflags --libs gl glu glew Magick++ assimp')

lib_objs = env.Object([Glob('libs/*.cpp'), 'image.cpp'])

env.Program('test_geometry_info.cpp')
env.Program(['test_image.cpp', lib_objs])
env.Program(['test_image_row.cpp', lib_objs])  # nedokoncene
#env.Program(['test_geometry.cpp', lib_objs])  # nedokoncene

env.Program(['test_adapt.cpp'])
