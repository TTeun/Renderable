#ifndef BLACKSHADER_H
#define BLACKSHADER_H

#include <QOpenGLShaderProgram>

class BlackShader : public QOpenGLShaderProgram
{
public:
  BlackShader(QObject *parent = 0);

  void init();
  void updateUniforms(QMatrix4x4 &projectionMatrix, QMatrix4x4 &modelViewMatrix);

private:
  GLint m_projecionMatrixUniform;
  GLint m_modelViewMatrixUniform;
};

#endif // BLACKSHADER_H
