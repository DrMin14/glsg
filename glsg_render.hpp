#ifndef _GLSG_RENDER_H_
#define _GLSG_RENDER_H_

#include "glsg_define.hpp"
#include "glsg_shader.hpp"
#include "glsg_mesh.hpp"

_GLSG_BEGIN



enum class draw_mode
{
      POINTS        = GL_POINTS
    , LINES         = GL_LINES
    , LINE_LOOP     = GL_LINE_LOOP
    , LINE_STRIP    = GL_LINE_STRIP
    , TRIANGLES     = GL_TRIANGLES
    , TRIANGLE_STRIP    = GL_TRIANGLE_STRIP
    , TRIANGLE_FAN      = GL_TRIANGLE_FAN
    , LINES_ADJACENCY   = GL_LINES_ADJACENCY
    , LINE_STRIP_ADJACENCY      = GL_LINE_STRIP_ADJACENCY
    , TRIANGLES_ADJACENCY       = GL_TRIANGLES_ADJACENCY
    , TRIANGLE_STRIP_ADJACENCY  = GL_TRIANGLE_STRIP_ADJACENCY
    , PATCHES = GL_PATCHES
};

class render_t
{
public:
    inline static void
    gl_load()
    { gladLoadGL(); }

    inline static void
    enable(int32_t _gldef)
    { glEnable(_gldef); }
    inline static void
    disable(int32_t _gldef)
    { glDisable(_gldef); }

public:
    inline void
    draw(mesh_t* _mesh, draw_mode _mode)
    {
        _mesh->bind();
        glDrawElements((GLenum)_mode, _mesh->sizeof_EBO(), GL_UNSIGNED_INT, NULL);
    }

    inline void
    clear(uint32_t _flag)
    { glClear(_flag); }

    inline void 
    set_clear_color(float _r, float _g, float _b, float _a)
    { glClearColor(_r, _g, _b, _a); }
    inline void
    set_viewport(int _x, int _y, int _w, int _h)
    { glViewport(_x, _y, _w, _h); }
};



_GLSG_END

#endif
