// Includes essential throughout the whole project.
// This file is meant to be used as a precompiled header on compilers supporting it.

#pragma once

#ifdef WIN32
#include <windows.h>
#endif

#include <string>
#include <functional>
#include <vector>
#include <memory>
#include <future>
#include <chrono>
#include <map>
#include <array>
#include <random>

// OGL:
#include <gl/gl.h>

// GLUT:
#include <glut.h>

// Sole (UUID generator):
#include <sole.hpp>
