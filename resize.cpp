// Project UID af1f95f547e44c8ea88730dfb185559d
#include <fstream>
#include <iostream>
#include <sstream>
#include "Matrix.h"
#include "Image.h"
#include "processing.h"
using namespace std;
int main(int argc, const char* argv[]) {

    string inputName = argv[1];
    string outputName = argv[2];
    int desWidth = atoi(argv[3]); 
    int desHeight = 0;
    Image* img = new Image;
    ifstream opener;
    opener.open(inputName);
    
    // check ifstream open
    if (!opener.is_open()) {
        cout << "Error opening file: " << inputName << endl;
        delete img;
        return 2;
    }

    // init image after open
    Image_init(img, opener);

    // check width within bounds
    if (desWidth <= 0 || desWidth > Image_width(img)) {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
            << "WIDTH and HEIGHT must be less than or equal to original" << endl;
    }

    // check if new height desired
    if (argc == 5) {
        desHeight = atoi(argv[4]);

        // check height within bounds
        if (desHeight <= 0 || desHeight > Image_height(img)) {
            cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
                << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        }
        else {
            desHeight = Image_height(img);
        }
    }

    

    ofstream outputer;
    outputer.open(outputName);
    if (!outputer.is_open()) {
        cout << "Error opening file: " << outputName << endl;
        delete img;
        return 2;
    }
    
    // commence image changes
    seam_carve(img, desWidth, desHeight);
    Image_print(img, outputer);
    delete img;
}
