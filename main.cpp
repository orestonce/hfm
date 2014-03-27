#include <fstream>
#include <iostream>
#include <cstdlib>
#include "haffuman.h"

//

int main(int argc,char *argv[]) {
	
	if (argc != 4) {
		std::cout << "Useage : " << argv[0] << " {input_file} {tmp_file} {output_file}" << std::endl;
		return EXIT_FAILURE;
	}
	const char *inname	= argv[1];
	const char *tmpname	= argv[2];
	const char *depressname	= argv[3];

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

    return EXIT_SUCCESS;
}
