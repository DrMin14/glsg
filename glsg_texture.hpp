#ifndef _GLSG_TEXTURE_H_
#define _GLSG_TEXTURE_H_

#include "glsg_define.hpp"

_GLSG_BEGIN



enum class color_formet
{
	  RED	= GL_RED
	, RG	= GL_RG
	, RGB	= GL_RGB
	, RGBA	= GL_RGBA
};

class texture2d_t
{
public:
	static inline void
	tex_uint(shader_t* _shader, const char* _uniform, GLuint _slot)
	{ glUniform1i(_shader->get_uniform_location(_uniform), _slot); }
	static inline void 
	tex_parameteri(GLenum _pname, GLint _param)
	{ glTexParameteri(GL_TEXTURE_2D, _pname, _param); }

private:
	GLuint		m_id;
	GLuint		m_unit;

public:	
	inline void
	bind(GLuint _slot)
	{
		m_unit = _slot;
		glActiveTexture(GL_TEXTURE0 + m_unit);
		glBindTexture(GL_TEXTURE_2D, m_id);
	}
	inline void
	unbind()
	{
		glActiveTexture(GL_TEXTURE0 + m_unit);
		glBindTexture(GL_TEXTURE_2D, NULL);
	}

	inline void
	size(int* _x, int* _y)
	{
		glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, _x);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, _y);
	}

public:
	texture2d_t(uint32_t _w, uint32_t _h, uint8_t* _pixels, GLuint _slot, color_formet _format)
	{
		glGenTextures(1, &m_id);
		bind(_slot);
		glTexImage2D(GL_TEXTURE_2D, 0, (GLenum)_format, _w, _h, 0, (GLenum)_format, GL_UNSIGNED_BYTE, _pixels);
		glGenerateMipmap(GL_TEXTURE_2D);
		unbind();
	}
	~texture2d_t()
	{ glDeleteTextures(1, &m_id); }
};



_GLSG_END

#endif