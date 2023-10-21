#include <iostream>
#include "SVGdraw.h"

using namespace std;

const int MAXF = 10;
const char *farby[MAXF] = {"red", "green", "blue", "black", "gray",
                           "yellow", "brown", "orange", "purple", "aqua"};

struct okno {
    int x1, y1, x2, y2, f, clicks = 0;
};

int main() {
    int o, k;
    cin >> o >> k;
    int x1, y1, x2, y2, f;
    vector<okno> okna;
    for (int i = 0; i < o; i++) {
        okno temp;
        cin >> temp.x1 >> temp.y1
            >> temp.x2 >> temp.y2 >> temp.f;
        okna.push_back(temp);
    }
    return 0;
}
