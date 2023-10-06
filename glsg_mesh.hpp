#ifndef _GLSG_MESH_H_
#define _GLSG_MESH_H_

#include "glsg_define.hpp"
#include "glsg_opengl.hpp"

_GLSG_BEGIN



class mesh_t
{
private:
	uint32_t m_VAO, m_VBO, m_EBO;
	uint32_t m_size_VBO, m_size_EBO;

public:
	void 
	link_attrib(GLuint _layout, GLuint _num_components, GLenum _type, GLsizei _stride, void* _offset)
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		glVertexAttribPointer(_layout, _num_components, _type, GL_FALSE, _stride, _offset);
		glEnableVertexAttribArray(_layout);
		glBindBuffer(GL_ARRAY_BUFFER, NULL);
	}

	uint32_t 
	sizeof_VBO() 
	{ return m_size_VBO; }
	uint32_t 
	sizeof_EBO()
	{ return m_size_EBO; }

	void 
	bind() 
	{ glBindVertexArray(m_VAO); };
	void 
	unbind() 
	{ glBindVertexArray(NULL); };

public:
	mesh_t(float* _vertices, uint32_t _vertices_size, uint32_t* _indices, uint32_t _indices_size)
		: m_VAO(NULL)
		, m_VBO(NULL)
		, m_EBO(NULL)
		, m_size_VBO(_vertices_size)
		, m_size_EBO(_indices_size)
	{
		glGenVertexArrays	(1, &m_VAO);
		glGenBuffers		(1, &m_VBO);
		glGenBuffers		(1, &m_EBO);
		glBindVertexArray	(m_VAO);
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * _vertices_size, _vertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * _indices_size, _indices, GL_STATIC_DRAW);
		glBindVertexArray(NULL);
	}
	~mesh_t()
	{
		glDeleteBuffers		(1, &m_EBO);
		glDeleteBuffers		(1, &m_VBO);
		glDeleteVertexArrays(1, &m_VAO);
	}
};



_GLSG_END

#endif