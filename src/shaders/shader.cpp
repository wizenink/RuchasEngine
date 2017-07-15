#include "shader.h"

Shader::Shader()
{
}


/*Shader::Shader(std::string vertexpath, std::string fragmentpath) :m_vertexpath(vertexpath), m_fragmentpath(fragmentpath)
{
	

	std::string vertexstring = utils::loadfile(vertexpath.c_str());
	std::string fragmentstring = utils::loadfile(fragmentpath.c_str());
	compileShaders(vertexstring, fragmentstring);
	

}*/

void Shader::compileShaders(std::string vertexstring, std::string fragmentstring)
{
	m_vertex = glCreateShader(GL_VERTEX_SHADER);
	m_fragment = glCreateShader(GL_FRAGMENT_SHADER);
	m_program = glCreateProgram();
	GLint status;
	GLchar message[MESSAGESIZE];
	const GLchar* cvertexstring = vertexstring.c_str();
	const GLchar* cfragmentstring = fragmentstring.c_str();

	glShaderSource(m_vertex, 1, &cvertexstring, NULL);
	glCompileShader(m_vertex);
	glGetShaderiv(m_vertex, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		glGetShaderInfoLog(m_vertex, MESSAGESIZE, NULL, message);
		std::cerr << "Compile error on vertex shader:" <<  message << std::endl; // TODO: Logging system
	}

	glShaderSource(m_fragment, 1, &cfragmentstring, NULL);
	glCompileShader(m_fragment);
	glGetShaderiv(m_fragment, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		glGetShaderInfoLog(m_fragment, MESSAGESIZE, NULL, message);
		std::cerr << "Compile error on fragment shader:" << message << std::endl; // TODO: Logging system
	}

	m_program = glCreateProgram();
	glAttachShader(m_program, m_vertex);
	glAttachShader(m_program, m_fragment);
	glLinkProgram(m_program);

	glGetProgramiv(m_program, GL_LINK_STATUS, &status);
	if (status != GL_TRUE)
	{
		glGetProgramInfoLog(m_program, MESSAGESIZE, NULL, message);
	}


}
Shader::~Shader()
{
	glUseProgram(0);
	glDetachShader(m_program, m_vertex);
	glDetachShader(m_program, m_fragment);

	glDeleteShader(m_vertex);
	glDeleteShader(m_fragment);
	glDeleteProgram(m_program);
}
GLuint Shader::getProgram() noexcept
{
	return m_program;
}

void Shader::bind()
{
	glUseProgram(m_program);
}

void Shader::unbind()
{
	glUseProgram(0);
}