#pragma once
#include "support_a_dessin.h"
#include "machin.h"

class Bloc : public Machin {
    void evolue(double dt) {};
    virtual void dessine_sur(SupportADessin& support) override { support.dessine(*this); }
};