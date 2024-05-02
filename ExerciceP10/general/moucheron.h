#pragma once
#include "quitourne.h"

class Moucheron : public QuiTourne {
public:
    virtual void dessine_sur(SupportADessin& support) override { support.dessine(*this); }
};