//
//  main.cpp
//  splitreadsbymovie
//
//  Created by Zhixing Feng on 17/3/22.
//  Copyright © 2017年 Icahn School of Medicine at Mount Sinai. All rights reserved.
//

#include "splitreadsbymovie.h"

void test()
{
     map<string, int64_t> moviename = getmoviename("test/test.seq");
     map<string, int64_t>::iterator it;
     for (it=moviename.begin(); it!=moviename.end(); it++)
     cout << it->first << ": " << it->second << endl;
     
     splitreadsbymovie("test/test.seq", "test");

}

int main(int argc, char* argv[])
{
    if (argc==1){
        cout << "splitreadsbymovie fasta_file outdir" << endl;
        return 0;
    }else{
        if (argc != 3){
            cout << "splitreadsbymovie fasta_file outdir" << endl;
            return 1;
        }
    }
    string fasta_file = argv[1];
    string outdir = argv[2];
    splitreadsbymovie(fasta_file, outdir);
    return 0;
}
