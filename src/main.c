#include <stdio.h>
#include <string.h>
#include "pikaScript.h"
#include "pikaVM.h"
#include <wchar.h>
#include <locale.h>

wchar_t helpmsg[]=\
L"这套源码可根据下列选择而编译为五种执行方式。\n\
所对应的执行程序已分别抄送到example_exe 文件夹下\n\
的子文件夹，对应如下：\n\
\t选项\t\t\t文件夹\n\
START_FROM_FIRWARE\tstart_from_firmware\n\
START_FROM_STRING\tstart_from_string\n\
START_FROM_LIB\tstart_from_lib\n\
RUN_SINGLE_FILE\trun_single_file\n\
RUN_MULTI_FILES\trun_multi_files\n\
";


//-- only select one of the following:
// NOTE, this is already defined in property sheet of related config
//#define START_FROM_FIRMWARE  // related to config: firmware_start_Debug (x64)
//#define START_FROM_STRING    // related to config: string_start_Debug (x64)
//#define RUN_SINGLE_FILE      // related to config: single_file_run_Debug (x86)
//#define RUN_MULTI_FILES
//#define START_FROM_LIB
//------------------------
#define START_FROM_FIRMWARE  0
#define START_FROM_STRING    1
#define RUN_SINGLE_FILE      2
#define RUN_MULTI_FILES      3
#define START_FROM_LIB       4
//
// 
//#define NO_SHELL

int main(int argc, char** argv)
{
    // 设置本地化环境
    setlocale(LC_ALL, "");
    printf("[Info] System init OK!\r\n");
    wprintf(L"%ls", helpmsg);
#if PIKA_STARTUP_TYPE_INT == START_FROM_FIRMWARE
    // start from firmware
    PikaObj* pikaMain = pikaScriptInit(); // no dependancy, need precompile

#elif PIKA_STARTUP_TYPE_INT == START_FROM_STRING
    // start from string
    PikaObj* pikaMain = pikaScriptInit(); // no dependancy, need precompile
    obj_run(pikaMain, "print('** start from string by calling obj_run')"); // no dependancy, compile in runtime, slower

#elif PIKA_STARTUP_TYPE_INT == RUN_SINGLE_FILE
    // run single file
    PikaObj* pikaMain = pikaScriptInit(); // no dependancy, need precompile
    pikaVM_runSingleFile(pikaMain, "test2.py");

#elif PIKA_STARTUP_TYPE_INT == RUN_MULTI_FILES
    // run multiple file,
    // note* need a folder: pikascript-api for storing the compiled result
    PikaObj* pikaMain = newRootObj("pikaMain", New_PikaMain);
    pikaVM_runFile(pikaMain, "test_mfiles.py");

#elif PIKA_STARTUP_TYPE_INT == START_FROM_LIB
    // direct start from library
    // no compile at runtime, save flash life, start faster
    PikaObj* pikaMain = newRootObj("pikaMain", New_PikaMain);
    obj_linkLibraryFile((PikaObj*) pikaMain, "pikascript-api/pikaModules.py.a");
    obj_runModule(pikaMain, "start_from_lib");
#endif

#ifndef NO_SHELL
    // start with interactive
    pikaScriptShell(pikaMain);  // need pika_platform_getchar() support
#endif
   
    
    return 0;
}
