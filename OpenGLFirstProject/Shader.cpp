// Headers being used
#include "Shader.h"

// Libraries being used
#include <iostream>
#include <fstream>

/**
 * Checks the particular shader error flag for the particular shader
 *
 * @param shader    the shader being checked
 * @param flag      the error flag being checked
 * @param isProgram true if the shader is a complete program
 * @param errmsg    the error message of the program
 */
static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errmsg) {
	// Buffers
	GLint success = 0;
	GLchar error[1024];

	// Get flag status
	if (isProgram) glGetProgramiv(shader, flag, &success);
	else glGetShaderiv(shader, flag, &success);

	// Error if status is false
	if (success == GL_FALSE) {
		if (isProgram) glGetProgramInfoLog(shader, sizeof(error), NULL, &error[0]);
		else glGetShaderInfoLog(shader, sizeof(error), NULL, &error[0]);
		std::cerr << errmsg << ": '" << error << "'" << std::endl;
	}
}

/**
 * Compiles shader from the given filename
 *
 * @param filename   the name of the shader to compile
 * @param shadertype the type of shader being compiled
 */
static GLuint CompileShader(const std::string& filename, GLenum shadertype) {
	// Read shader code
	std::string code, line;
	std::ifstream file;
	file.open(filename);
	if (file.is_open()) {
		while (file.good()) {
			getline(file, line);
			code.append(line + "\n");
		}
	} else {
		std::cerr << "SHADERERROR: Cannot read file '" + filename + "'" << std::endl;
	}

	// Create shader
	GLuint shader = glCreateShader(shadertype);
	if (shader == 0) std::cerr << "SHADERERROR: Shader creation failed!" << std::endl;

	// Put source
	const GLchar* sources[1];
	GLint sourceLengths[1];
	sources[0] = code.c_str();
	sourceLengths[0] = code.length();

	// Compile shader
	glShaderSource(shader, 1, sources, sourceLengths);
	glCompileShader(shader);
	CheckShaderError(shader, GL_COMPILE_STATUS, false, "SHADERERROR: Shader compilation failed!");

	// Return compiled shader
	return shader;
}

/**
 * Loads a shader from the given filename
 *
 * @param filename the name of the file to load
 */
Shader::Shader(const std::string& filename)
{
	// Create program and compile shaders
	m_program = glCreateProgram();
	m_shaders[0] = CompileShader(filename + ".v", GL_VERTEX_SHADER);
	m_shaders[1] = CompileShader(filename + ".f", GL_FRAGMENT_SHADER);

	// Attach shaders to program
	for (unsigned i = 0; i < NUM_SHADERS; i++) {
		glAttachShader(m_program, m_shaders[i]);
	}

	// Bind attributes
	glBindAttribLocation(m_program, 0, "position");
	glBindAttribLocation(m_program, 1, "texcoord");

	// Link and validate program
	glLinkProgram(m_program);
	CheckShaderError(m_program, GL_LINK_STATUS, true, "SHADERERROR: Program linking failed!");
	glValidateProgram(m_program);
	CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "SHADERERROR: Shader program invalid!");
}

/**
 * Destroys the shader
 */
Shader::~Shader()
{
	// Detach and delete shaders
	for (unsigned i = 0; i < NUM_SHADERS; i++) {
		glDetachShader(m_program, m_shaders[i]);
		glDeleteShader(m_shaders[i]);
	}
	// Delete program
	glDeleteProgram(m_program);
}

/**
 * Binds the shader
 */
void Shader::Bind()
{
	glUseProgram(m_program);
}

/**
 * Returns the program
 *
 * @return the program
 */
GLuint Shader::GetProgram()
{
	return m_program;
}