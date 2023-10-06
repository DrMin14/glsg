#ifndef _GLSG_DEBUG_H_
#define _GLSG_DEBUG_H_

#ifdef GLSG_NDEBUG
#define warning(str)	(void(0))

#else
#include <cstdio>

using _debug_log = const char[];

inline void
warning(_debug_log _str)
{ puts(_str); }

#endif

#endif
