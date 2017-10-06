#include <QOpenGLFunctions_4_1_Core>
#include <QtGui/QWindow>

class QPainter;
class QOpenGLContext;
class QOpenGLPaintDevice;

class OpenGLWindow : public QWindow, protected QOpenGLFunctions_4_1_Core
{
  Q_OBJECT
public:
  explicit OpenGLWindow(QWindow *parent = 0);
  ~OpenGLWindow();

  virtual void render(QPainter *painter);
  virtual void render();
  virtual void initialize();
  void setAnimating(bool animating);
  static unsigned int const maxIndex;
  QOpenGLFunctions_4_1_Core *glFunctions();

public slots:
  void renderLater();
  void renderNow();

protected:
  bool event(QEvent *event) override;
  void exposeEvent(QExposeEvent *event) override;

  QOpenGLContext *m_context;
  QOpenGLFunctions_4_1_Core *m_glFunctions;

private:
  bool m_animating;
  QOpenGLPaintDevice *m_device;
};
