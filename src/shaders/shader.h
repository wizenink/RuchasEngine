#ifndef SHADER_H
#define SHADER_H
#define MESSAGESIZE 512
#include "../glad/glad.h"
#include "../utils/fileloader.h"
#include <string>
#include <iostream>
class Shader
{
private:
	std::string m_vertexpath;
	std::string m_fragmentpath;
	GLuint m_vertex;
	GLuint m_fragment;
	GLuint m_program;
public:
	Shader(std::string vertexpath, std::string fragmentpath);
	Shader();
	void compileShaders(std::string vertexstring, std::string fragmentstring);
	~Shader();
	GLuint getProgram() noexcept;
	void bind();
	void unbind();

};
#endif // !SHADER_H
