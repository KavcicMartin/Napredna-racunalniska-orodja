#include <iostream>
#include <cmath>

// Funkcija e^(3x)
double e_3x(double x) {
    return exp(3 * x);
}

// arctan(x) v Taylorju
double arctan_taylor(double x, int terms = 5) {
    double resitev = 0;
    for (int n = 0; n < terms; ++n) {
        resitev += pow(-1, n) * pow(x, 2 * n + 1) / (2 * n + 1);
    }
    return resitev;
}

// Trapezna metoda
double trapezna_metoda(double (*func)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double resitev = 0.5 * (func(a) + func(b));
    for (int i = 1; i < n; ++i) {
        resitev += func(a + i * h);
    }
    resitev *= h;
    return resitev;
}

int main() {
    // Meje integrala
    double a = 0;
    double b = M_PI / 4;

    // Število podintervalov
    int n = 10000;

    // Uporabi trapezno metodo za izračun integrala
    double resitev = trapezna_metoda([](double x) { return e_3x(x) * arctan_taylor(x / 2); }, a, b, n);

    std::cout << "Približna vrednost integrala: " << resitev << std::endl;

    return 0;
}
