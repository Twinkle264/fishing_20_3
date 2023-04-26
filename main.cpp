#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    vector<string> riverFish;
    string fish;
    ifstream river("./files/river.txt");
    if (!river.is_open()) {
        cerr << "FILE READ ERROR!";
        return 1;
    }

    while (!river.eof()) {
        river >> fish;
        riverFish.push_back(fish);
    }

    fish = "";
    river.close();

    cout << "Enter the name of the fish to be caught" << endl;
    cout << "(sunfish, shad, carp, bass, bullhead, walleye, catfish): ";
    cin >> fish;

    ofstream basket("./files/basket.txt", ios::app);
    if (!basket.is_open()) {
        cerr << "FILE WRITE ERROR";
        return 1;
    }

    int countFish = 0;
    for (int i = 0; i < riverFish.size(); ++i) {
        if (fish == riverFish[i]) {
            basket << riverFish[i] << endl;
            ++countFish;
        }
    }

    basket.close();

    cout << endl;
    cout << "The number of fish caught for the current fishing trip: " << countFish;
    return 0;
}
