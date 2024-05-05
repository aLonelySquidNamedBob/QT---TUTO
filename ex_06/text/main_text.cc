#include <iostream>
#include "text_viewer.h"
#include "contenu.h"
using namespace std;

int main()
{
  TextViewer ecran(cout);
  Contenu c;
  c.dessine_sur(ecran);
  return 0;
}
