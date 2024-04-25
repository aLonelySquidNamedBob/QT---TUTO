#include "contenu.h"
#include <math.h>

void Contenu::evolue(double dt) {
    jitter += 0.001 * dt;

    if (sign_x) {
        x += 0.01 * dt;
    } else {
        x -= 0.01 * dt;
    }

    if (sign_y) {
        y += 0.01 * dt;
    } else {
        y -= 0.01 * dt;
    }

    if (x < 0 || x > 4) sign_x = not sign_x;
    if (y < 0 || y > 4) sign_y = not sign_y;

}