#include <iostream>
#include <cmath>

struct ponto2d {double x, y;};

double dist_euclidiana(ponto2d p1, ponto2d p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    double x1, x2, y1, y2;

    scanf("%lf %lf %lf %lf", &x1, &x2, &y1, &y2);

    ponto2d pontoA = {x1, x2};
    ponto2d pontoB = {y1, y2};

    printf("A distancia euclidiana eh: %lf ", dist_euclidiana(pontoA, pontoB));

    return 0;
}