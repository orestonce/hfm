#include <fstream>
#include <iostream>
#include <haffuman.h>

//
const char *inname= "d:/in.txt";
const char *tmpname= "D:/tmp";
const char *depressname = "d:/out.txt";

int main(void) {
    std::ifstream infile (inname);

    if (!infile ) {
        std::cerr << "Open file failed ." << std::endl;
        return 0;
    }
    Haffuman hfm(infile);
    infile.close();

    std::ofstream outfile(tmpname) ;

    infile.open(inname);
    hfm.encoding(infile ,outfile);
    infile.close();
    outfile.close();

    infile.open(tmpname);
    outfile.open(depressname);

    hfm.decoding(infile ,outfile);
    infile.close();
    outfile.close();

    std::cout << 321.0/8 << std::endl;

    return 0;
}
