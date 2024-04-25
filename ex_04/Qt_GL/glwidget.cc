#include <QKeyEvent>
#include <QTimerEvent>
#include <QMatrix4x4>
#include "glwidget.h"

// ======================================================================
void GLWidget::initializeGL()
{
  vue.init();
}

// ======================================================================
void GLWidget::resizeGL(int width, int height)
{
  /* On commance par dire sur quelle partie de la 
   * fenêtre OpenGL doit dessiner.
   * Ici on lui demande de dessiner sur toute la fenêtre.
   */
  glViewport(0, 0, width, height);

  /* Puis on modifie la matrice de projection du shader.
   * Pour ce faire on crée une matrice identité (constructeur 
   * par défaut), on la multiplie par la droite par une matrice
   * de perspective.
   * Plus de détail sur cette matrice
   *     http://www.songho.ca/opengl/gl_projectionmatrix.html
   * Puis on upload la matrice sur le shader à l'aide de la
   * méthode de la classe VueOpenGL
   */
  QMatrix4x4 matrice;
  matrice.perspective(70.0, qreal(width) / qreal(height ? height : 1.0), 1e-3, 1e5);
  vue.setProjection(matrice);
}

// ======================================================================
void GLWidget::paintGL()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  c.dessine_sur(vue);
}


// ======================================================================
void GLWidget::keyPressEvent(QKeyEvent* event)
{
  constexpr double petit_angle(5.0); // en degrés
  constexpr double dist = 5;
  constexpr double petit_pas(1.0);

  switch (event->key()) {

  case Qt::Key_PageUp:
  case Qt::Key_Z:
    vue.translate(0, 0, dist);
    vue.rotate(-petit_angle, 1, 0, 0);
    vue.translate(0, 0, -dist);
    break;

  case Qt::Key_PageDown:
  case Qt::Key_S:
    vue.translate(0, 0, dist);
    vue.rotate(petit_angle, 1, 0, 0);
    vue.translate(0, 0, -dist);
    break;

  case Qt::Key_Q:
    vue.translate(0, 0, dist);
    vue.rotate(-petit_angle, 0, 1, 0);
    vue.translate(0, 0, -dist);
    break;

  case Qt::Key_D:
    vue.translate(0, 0, dist);
    vue.rotate(petit_angle, 0, 1, 0);
    vue.translate(0, 0, -dist);
    break;

  case Qt::Key_Space:
    vue.translate(0.0, -petit_pas, 0.0);
    break;

  case Qt::Key_Shift:
    vue.translate(0.0,  petit_pas, 0.0);
    break;

  case Qt::Key_A:
    vue.translate(0, 0, dist);
    vue.rotate(-petit_angle, 0, 0, 1);
    vue.translate(0, 0, -dist);
    break;

  case Qt::Key_E:
    vue.translate(0, 0, dist);
    vue.rotate(petit_angle, 0, 0, 1);
    vue.translate(0, 0, -dist);
    break;

  case Qt::Key_Home:
    vue.initializePosition();
    break;
  };

  update(); // redessine
}
