#ifndef _GLSG_SHADER_H_
#define _GLSG_SHADER_H_

#include "glsg_debug.hpp"
#include "glsg_define.hpp"
#include "glsg_opengl.hpp"

_GLSG_BEGIN



enum class shader_type
{
	  vertex	= GL_VERTEX_SHADER
	, tess_ctl	= GL_TESS_CONTROL_SHADER
	, tess_evl	= GL_TESS_EVALUATION_SHADER
	, geometry	= GL_GEOMETRY_SHADER
	, fragment	= GL_FRAGMENT_SHADER
	, compute	= GL_COMPUTE_SHADER
};

class shader_t
{
private:
	GLuint m_id;

private:
	int 
	_check_shader_log(GLuint _shader) 
	{
		int len		= 0;
		int chWrittn	= 0;
		char* log;
		glGetShaderiv(_shader, GL_INFO_LOG_LENGTH, &len);
		if (0 < len) 
		{
			log = new char[len];
			glGetShaderInfoLog(_shader, len, &chWrittn, log);
			warning("SHADER_COMPILE_ERROR");
			warning(log);
			delete[] log;
			return -1;
		}
		return 0;
	}
	int 
	_check_program_log(GLuint _prog)
	{
		int len		= 0;
		int chWrittn	= 0;
		char* log;
		glGetProgramiv(_prog, GL_INFO_LOG_LENGTH, &len);
		if (0 < len) 
		{
			log = new char[len];
			glGetProgramInfoLog(_prog, len, &chWrittn, log);
			warning("PROGRAM_LINK_ERROR");
			warning(log);
			delete[] log;
			return -1;
		}
		return 0;
	}

public:
	inline void
	create()
	{ m_id = glCreateProgram(); }
	inline void
	destroy()
	{ glDeleteProgram(m_id), m_id = NULL; }

	inline GLuint
	id()
	{ return m_id; }
	inline void
	use()
	{ glUseProgram(m_id); }

	inline GLuint 
	get_uniform_location(const char* _pram)
	{ return glGetUniformLocation(m_id, _pram); }

	void 
	compile(shader_type _type, const char _src[])
	{
		GLuint shader = glCreateShader((GLuint)_type);
		glShaderSource	(shader, 1, &_src, NULL);
		glCompileShader	(shader);
		if (!_check_shader_log(shader)) 
			glAttachShader(m_id, shader);
		glDeleteShader	(shader);
	}
	inline void
	link()
	{
		glLinkProgram(m_id);
		_check_program_log(m_id);
	}

public:
	shader_t()
		: m_id(0)
	{ create(); }
	~shader_t()
	{ destroy(); }
};



_GLSG_END

#endif
