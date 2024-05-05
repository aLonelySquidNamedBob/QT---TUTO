#include <iostream> // pour endl
#include "text_viewer.h"
#include "contenu.h"

void TextViewer::dessine(Contenu const&)
{
  /* Dans ce premier exemple très simple, on n'utilise       *
   * pas l'argument Contenu. Nous ne l'avons donc pas nommé. */

  flot << "une sphère" << std::endl;
  flot << "une autre sphère à droite" << std::endl;
  flot << "une 3e sphère au dessus" << std::endl;
}
