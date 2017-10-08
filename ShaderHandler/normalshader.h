#ifndef NORMALSHADER_H
#define NORMALSHADER_H

#include <QOpenGLShaderProgram>

class NormalShader : public QOpenGLShaderProgram
{
public:
  NormalShader(QObject *parent = 0);

  void init();
  void updateUniforms(QMatrix4x4 &projectionMatrix, QMatrix4x4 &modelViewMatrix);

private:
  GLint m_projecionMatrixUniform;
  GLint m_modelViewMatrixUniform;
};

#endif // NORMALSHADER_H
