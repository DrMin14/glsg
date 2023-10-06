#ifndef _GLSG_DEFINE_H_
#define _GLSG_DEFINE_H_

#define _GLSG_BEGIN namespace glsg {
#define _GLSG_END }

#ifdef GLSG_MSVC_SUBSYSTEM_WINDOWS
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif

#include <cstdlib>
#include <cstdint>

#include "glsg_debug.hpp"



#endif