#include <iostream>
#include <fstream>
#include <cstdint>
#include <netinet/in.h>

using namespace std;

int main(int argc, char* argv[]) {
    if(argc != 3) {
        cerr << "Error: Wrong Parameter\n";
        cerr << "syntax : add-nbo <file1> <file2>\n";
        cerr << "sample : add-nbo a.bin c.bin" << endl;

        return 1;
    }

    string strA, strB;
    uint32_t a, b;
    ifstream fileA, fileB;
    
    fileA.open(argv[1]);
    fileB.open(argv[2]);

    a = 1000, b = 1000;

    if(fileA.is_open()) fileA.read((char*)&a, sizeof(a));
    if(fileB.is_open()) fileB.read((char*)&b, sizeof(b));

    a = ntohl(a);
    b = ntohl(b);

    cout << a << "(0x" << hex << a << ") + ";
    cout << dec << b << "(0x" << hex << b << ") = ";
    cout << dec << a + b << "(0x" << hex << a + b << ')' << endl;

    fileA.close();
    fileB.close();

    return 0;
}