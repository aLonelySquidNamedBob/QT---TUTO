#pragma once

#include "dessinable.h"
#include "support_a_dessin.h"
#include <memory>
#include <vector>
#include "machin.h"

class Contenu : public Dessinable {
public:
  Contenu() = default;
  virtual ~Contenu() = default;
  Contenu(Contenu const&) = default;
  Contenu& operator=(Contenu const&) = default;
  Contenu(Contenu&&) = default;
  Contenu& operator=(Contenu&&) = default;

  virtual void dessine_sur(SupportADessin& support) override {
    for (auto& machin : machins) {
      machin->dessine_sur(support);
    }
  }

  void evolue(double dt) { for (auto& machin : machins) { machin->evolue(dt); } }

  void ajoute(std::unique_ptr<Machin> machin) { machins.push_back(std::move(machin)); }

  double infos() const { return machins.size(); }

private:
  std::vector<std::unique_ptr<Machin>> machins;
};
