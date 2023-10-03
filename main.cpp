//My name is James Cangelosi and I certify that this program is my work and my work only
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
    fout << filetype << endl;
    // read the comment
    string comment;
    getline(file, comment);
    if(comment[0] == '#'){
        getline(file, comment);
    }
    stringstream ss(comment);

    int width, height, maxValue;
    ss >> width >> height;

    file >> maxValue;

    fout << comment << endl;
    fout << maxValue<<endl;

    for(int l=0; l<height; l++){
        for(int c=0; c<width; c++){
            int pix;
            file >> pix;
            pix = maxValue - pix;
            fout << pix << " ";
        }
    }

    // Close the file
    file.close();

    return 0;
}