#ifndef MAINSHADER_H
#define MAINSHADER_H

#include <QOpenGLShaderProgram>

class MainShader : public QOpenGLShaderProgram
{
public:
  MainShader(QObject *parent = 0);

  void init();
  void updateUniforms(QMatrix4x4 &projectionMatrix, QMatrix4x4 &modelViewMatrix);

private:
  QVector3D m_lightPosition = QVector3D(0.0, 0.0, -10.0);
  GLint m_projecionMatrixUniform;
  GLint m_modelViewMatrixUniform;
  GLint m_lightPosUniform;
};

#endif // MAINSHADER_H
