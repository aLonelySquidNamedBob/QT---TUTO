#include <iostream> // pour endl
#include "text_viewer.h"
#include "bloc.h"
#include "moucheron.h"
#include "dervish.h"


void TextViewer::dessine(Bloc const& a_dessiner)
{
  flot << "Moucheron : immobile" << std::endl;
}

void TextViewer::dessine(Dervish const& a_dessiner)
{
  flot << "Moucheron : " << a_dessiner.infos() << std::endl;
}

void TextViewer::dessine(Moucheron const& a_dessiner)
{
  flot << "Moucheron : " << a_dessiner.infos() << std::endl;
}
