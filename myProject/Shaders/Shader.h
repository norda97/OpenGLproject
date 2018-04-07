#ifndef SHADER_H
#define SHADER_H

#define PATH "./Shaders/"

#include <string>
#include "glm.hpp"
#include "glew.h"

class Shader {

public:
	Shader(const std::string& vertexFile, const std::string& fragmentFile);
	virtual ~Shader();

	void useProgram() const;
	const GLuint getID() const;

	void loadInt(GLuint location, int value);
	void loadFloat(GLuint location, float value);

	void loadVector2(GLuint location, const glm::vec2& vect);
	void loadVector3(GLuint location, const glm::vec3& vect);
	void loadVector4(GLuint location, const glm::vec4& vect);

	void loadMatrix4(GLuint location, const glm::mat4& matrix);

	virtual void updateUniforms();
private:
	GLuint m_id;

	GLuint loadShaders(const std::string& vertexShader, const std::string& fragmentShader);
	GLuint linkProgram(GLuint vertexShaderID, GLuint fragmentShaderID);
	GLuint compileShader(const GLchar* source, GLenum shaderType);
	const std::string loadFile(const std::string & shaderFile);
};


#endif 