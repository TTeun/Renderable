#include "renderable.h"

Renderable::Renderable() : m_shaderProgram(0)
{
}

Renderable::~Renderable()
{
  delete m_shaderProgram;
}
