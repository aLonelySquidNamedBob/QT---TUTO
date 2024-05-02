#pragma once
#include "dessinable.h"

class Machin : public Dessinable {
public:
    virtual void evolue(double dt) = 0;
    virtual void dessine_sur(SupportADessin&) = 0;
};