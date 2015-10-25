env = Environment(
	CXXFLAGS=['-std=c++11', '-g', '-O0', '-Wall', '-Wno-sign-compare'],
	CPPPATH=['.'],
	CPPDEFINES=['GLM_FORCE_RADIANS'])

geom_objs = env.Object(['utility.cpp'])

env.Program(['test_expand.cpp'])
env.Program(['test_rotations.cpp', geom_objs])
