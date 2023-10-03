#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string filename;
    getline(cin, filename); // for be able to read spaces

    // Open the file
    ifstream file(filename);
    ofstream fout("inv_" + filename);

    // Check if the file is open
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    string filetype;
    getline(file, filetype);
    // read the comment
    string comment;
    getline(file, comment);

    int width, height, maxValue;
    file >> width >> height >> maxValue;

    for(int l=0; l<height; l++){
        for(int c=0; c<width; c++){
            int pix;
            file >> pix;
            // here you have to work more
            pix = maxValue - pix;
        }
    }

    // Read the contents of the file into a stringstream
    stringstream ss;
    ss << file.rdbuf(); // read the whole file buffer and stores it into a string stream

    // Close the file
    file.close();

    // Convert the stringstream into a string
    string contents = ss.str();

    cout << contents << endl; // prints the whole file at once

    return 0;
}