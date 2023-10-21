#include <iostream>
#include "SVGdraw.h"

using namespace std;

const int MAXF = 10;
const char *farby[MAXF] = {"red", "green", "blue", "black", "gray",
                           "yellow", "brown", "orange", "purple", "aqua"};

struct window {
    int x1, y1, x2, y2, f, clicks = 0;
};

struct click {
    int x, y;
};

int main() {
    int o, k;
    cin >> o >> k;
    int x1, y1, x2, y2, f;
    vector<window> windows;
    vector<click> clicks;
    for (int i = 0; i < o; i++) {
        window temp;
        cin >> temp.x1 >> temp.y1
            >> temp.x2 >> temp.y2 >> temp.f;
        windows.push_back(temp);
    }
    for (int i = 0; i < k; i++) {
        click temp;
        cin >> temp.x >> temp.y;
        clicks.push_back(temp);
    }
    return 0;
}
