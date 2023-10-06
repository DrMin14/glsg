#ifndef _GLSG_DEBUG_H_
#define _GLSG_DEBUG_H_

#ifdef GLSG_NDEBUG
#define warning(str)	(void(0))
#define error(str)		(void(0))



#else
#include <cstdio>
#include <cassert>

using _debug_log = const char[];



inline void
warning(_debug_log _str)
{ puts(_str); }
void
error(_debug_log _str)
{ puts(_str), assert(nullptr); }



#endif

#endif