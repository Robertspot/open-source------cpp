#ifndef SLX_COMMANDER

#define SLX_COMMANDER

#include"../deps/commander/commander.c"
#include<stdio.h>

namespace SeatChangeProcessor{

    FILE* __in = stdin;
    FILE* __out = stdout;

    void __input(command_t* __cmd);
    void __output(command_t* __cmd);

    void __input(command_t* __cmd){
        __in = fopen(__cmd->arg,"rb");
    }
    void __output(command_t* __cmd){
        __out = fopen(__cmd->arg,"wb");
    }
    void reg_cmd(int __argc,char** __argv){
        command_t __cmd;
        command_init(&__cmd,__argv[0],"1.0.0");
        command_option(&__cmd,"-i","--input<file>","Input from <file>.",__input);
        command_option(&__cmd,"-o","--output<file>","Output to <file>.",__output);
        command_parse(&__cmd,__argc,__argv);
    }
}

#endif