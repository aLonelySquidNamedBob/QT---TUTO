#pragma once

#include "dessinable.h"
#include "support_a_dessin.h"
#include <math.h>

class Contenu : public Dessinable {
public:
  virtual ~Contenu() = default;
  Contenu(Contenu const&) = default;
  Contenu& operator=(Contenu const&) = default;
  Contenu(Contenu&&) = default;
  Contenu& operator=(Contenu&&) = default;

  Contenu() = default;

  void evolue(double dt);

  double getX() const { return x; }
  double getY() const { return y; }
  double getTheta() const { return theta; }

  virtual void dessine_sur(SupportADessin& support) override {
    support.dessine(*this);
  }

private:
  double jitter;
  double x;
  double y;
  double theta;
  bool sign_x;
  bool sign_y;
};
