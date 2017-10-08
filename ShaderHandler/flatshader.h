#ifndef FLATSHADER_H
#define FLATSHADER_H

#include <QOpenGLShaderProgram>

class FlatShader : public QOpenGLShaderProgram
{
public:
  FlatShader(QObject *parent = 0);

  void init();
  void updateUniforms(QMatrix4x4 &projectionMatrix, QMatrix4x4 &modelViewMatrix);

private:
  GLint m_projecionMatrixUniform;
  GLint m_modelViewMatrixUniform;
};

#endif // FLATSHADER_H
