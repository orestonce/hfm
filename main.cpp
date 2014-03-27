#include <fstream>
#include <iostream>
#include <stdio.h>
#include "haffuman.h"

//
const char *inname= "in.txt";
const char *tmpname= "tmp";
const char *depressname = "out.txt";

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
	
	remove(tmpname);	

    return 0;
}
