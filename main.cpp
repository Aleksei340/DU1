#include <iostream>
#include <format>
#include "SVGdraw.h"

using namespace std;

const int MAXF = 10;
const char *farby[MAXF] = {"red", "green", "blue", "black", "gray",
                           "yellow", "brown", "orange", "purple", "aqua"};

struct window {
    int x1, y1, x2, y2, f, clicks = 0;
};

struct click {
    int x, y, windowNumber, f;
};

// Function which returning id of the window with received click
int checkInWhichWindow(click entry, vector<window>& windows) {
    for(int i = windows.size()-1; i >=0; i--) {
        //Taking window object
        window temp = windows[i];

        if(entry.x >= temp.x1 && entry.x <= temp.x2
            && entry.y >= temp.y1 && entry.y <= temp.y2) {
                windows[i].clicks += 1;
                return i;
        }
    }
}

int main() {
    int o, k;

    cin >> o >> k;

    vector<window> windows;
    vector<click> clicks;

    // Receiving data about windows from terminal
    for (int i = 0; i < o; i++) {
        window temp;
        cin >> temp.x1 >> temp.y1
            >> temp.x2 >> temp.y2 >> temp.f;
        windows.push_back(temp);
    }

    // Receiving data about clicks from terminal
    for (int i = 0; i < k; i++) {
        click temp;
        cin >> temp.x >> temp.y;
        temp.windowNumber = checkInWhichWindow(temp, windows);
        temp.f = windows[temp.windowNumber].f;
        clicks.push_back(temp);
    }

    // Terminal part of the task
    for(int i = 0; i < clicks.size(); i++) {
        cout << format("klik ({},{}) je v okne {}",
                       clicks[i].x, clicks[i].y, clicks[i].windowNumber)
             << endl;
    }

    for(int i = 0; i < windows.size(); i++) {
        cout << format("okno {} pocet klikov {}",
                       i, windows[i].clicks)
             << endl;
    }
    return 0;
}
