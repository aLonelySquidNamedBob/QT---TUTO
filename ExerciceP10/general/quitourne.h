#pragma once

#include "dessinable.h"
#include "support_a_dessin.h"
#include "machin.h"

class QuiTourne : public Machin {
public:
  QuiTourne(double a = 0.0) : angle(a) {}
  virtual ~QuiTourne() = default;
  QuiTourne(QuiTourne const&)            = default;
  QuiTourne& operator=(QuiTourne const&) = default;
  QuiTourne(QuiTourne&&)                 = default;
  QuiTourne& operator=(QuiTourne&&)      = default;

  virtual void dessine_sur(SupportADessin& support) = 0;

  void evolue(double dt) override;

  // accesseur
  double infos() const { return angle; }

private:
  double angle; /* pour le mouvement ;
                   dans cet exemple, juste une rotation
                   au cours du temps                    */
};
