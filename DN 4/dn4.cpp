#include <iostream>
#include <fstream>
#include <vector>


double diferencnanaprej(std::vector<std::pair<double, double>>& data, int idx, double dx) {
    return (-3 * data[idx].second + 4 * data[idx + 1].second - data[idx + 2].second) / (2 * dx);
}


double diferencnanazaj(std::vector<std::pair<double, double>>& data, int idx, double dx) {
    return (3 * data[idx].second - 4 * data[idx - 1].second + data[idx - 2].second) / (2 * dx);
}


double diferencnacentralna(std::vector<std::pair<double, double>>& data, int idx, double dx) {
    return (data[idx + 1].second - data[idx - 1].second) / (2 * dx);
}

int main() {
    std::ifstream inputFile("poly.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Datoteko poly.txt ni mozno odpreti\n";
        return 1;
    }

    int numOfValues;
    inputFile >> numOfValues;

    std::vector<std::pair<double, double>> data;
    double x, fx;
    for (int i = 0; i < numOfValues; ++i) {
        inputFile >> x >> fx;
        data.emplace_back(x, fx);
    }

    inputFile.close();

    double dx = 0.0294117647058822; // ∆x
    std::ofstream outputFile("diff_poly.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Datoteke diff_poly.txt ni mozno narediti\n";
        return 1;
    }


    for (int i = 0; i < numOfValues; ++i) {
        double odvod;
        if (i == 0) {
            odvod = diferencnanaprej(data, i, dx);
        }
        else if (i == numOfValues - 1) {
            odvod = diferencnanazaj(data, i, dx);
        }
        else {
            odvod = diferencnacentralna(data, i, dx);
        }
        outputFile << "Odvod f'(" << data[i].first << ") = " << odvod << std::endl;
    }

    outputFile.close();

    std::cout << "Odvodi shranjeni v diff_poly.txt\n";

    return 0;
}