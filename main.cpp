//
//  main.cpp
//  splitreadsbymovie
//
//  Created by Zhixing Feng on 17/3/22.
//  Copyright © 2017年 Icahn School of Medicine at Mount Sinai. All rights reserved.
//

#include "splitreadsbymovie.h"

int main(int argc, char* argv[])
{
    map<string, int64_t> moviename = getmoviename("test/test.seq");
    map<string, int64_t>::iterator it;
    for (it=moviename.begin(); it!=moviename.end(); it++)
        cout << it->first << ": " << it->second << endl;
    
    return 0;
}
