//
//  getmoviename.h
//  splitreadsbymovie
//
//  Created by Zhixing Feng on 17/3/22.
//  Copyright © 2017年 Icahn School of Medicine at Mount Sinai. All rights reserved.
//

#ifndef getmoviename_h
#define getmoviename_h

#include <string>
#include <map>
#include <zlib.h>  
#include <stdio.h>  
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdint>
#include <sstream>
#include <stdexcept>
#include <cstdint>
#include <cstdlib>

#include "kseq.h"  
using namespace std;

KSEQ_INIT(gzFile, gzread)  

inline vector<string> split(string s, char delim, bool rm_empty=true) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        if (rm_empty){
            if (item!="") tokens.push_back(item);
        }else{
            tokens.push_back(item);
        }
    }
    return tokens;
}

inline map<string, int64_t> getmoviename(string fasta_file)
{
    map<string, int64_t> moviename;
    map<string, int64_t>::iterator it;
    gzFile fp;  
    kseq_t *seq;  
    int l;  
    fp = gzopen(fasta_file.c_str(), "r"); // STEP 2: open the file handler 
    if (fp==NULL){
        cerr << "fail to open " + fasta_file << endl;
        exit(1);
    }
    seq = kseq_init(fp); // STEP 3: initialize seq  
    while ((l = kseq_read(seq)) >= 0) { // STEP 4: read sequence
        string cur_moviename = split(seq->name.s, '/')[0];
        it = moviename.find(cur_moviename);
        if (it==moviename.end()){
            moviename[cur_moviename] = 1;
        }else{
            moviename[cur_moviename] += 1;
        }
    }  
    kseq_destroy(seq); // STEP 5: destroy seq  
    gzclose(fp); // STEP 6: close the file handler  

    
    return moviename;
}


#endif /* getmoviename_h */
