#include <stdio.h>
#include <stdlib.h>

#include "stdx/stringx.h"
#include "stdx/iox.h"

#define TEMPLATES_PATH "/home/ele/Desktop/projects/C/cproj/templates"

int main(int argc, char** argv) {
    if (argc == 1 || strcmpx(argv[1], "help") || strcmpx(argv[1], "--help")) {
        puts("");
        puts("--------------------------------------------");
        puts("C\\C++ project manager for windows/unix-like");
        puts("--------------------------------------------");
        puts("");
        puts("cproj new [project_name] [template] - creates a new project from template (template will be \"c\" by default)");
        puts("cproj build - runs the \"build\" file inside the project");
        puts("cproj run - runs the \"build\" file inside the project and then runs the output executable");
        puts("cproj list - lists available templates");
        puts("cproj help - opens this window");
        puts("");
        return 0;
    }  

    // creating projects
    if (strcmpx(argv[1], "new")) {
        char* project_name = argv[2];
        char template[1024];

        snprintf(template, 1024, "%s/", TEMPLATES_PATH);
        #ifdef __unix__
            #define DEFAULT_TEMPLATE "c"
        #else
            #define DEFAULT_TEMPLATE "c-win"
        #endif

        if (argc == 4) strcat(template, argv[3]); else strcat(template, DEFAULT_TEMPLATE); // defaults to "c" if template arg doesnt exist
        
        if (!io_dir_exists(template)) {
            printf("[ERROR] INVALID TEMPLATE, COULD NOT FIND DIRECTORY \"%s\"\n", template);
            return 1;
        }

        if (io_dir_exists(project_name)) {
            printf("[ERROR] PROJECT \"%s\" ALREADY EXISTS\n", project_name);
            return 1;
        }

        char buf[1024];
        #ifdef __unix__
            snprintf(buf, 1024, "cp %s %s -r", template, project_name);
        #else
            snprintf(buf, 1024, "robocopy %s %s /E > nul", template, project_name);
        #endif
        system(buf);
    }
    // compiling/running projects
    else if (strcmpx(argv[1], "run") || strcmpx(argv[1], "build")) {
        #ifdef __unix__
            if (!io_file_exists("build")) {
                puts("[ERROR] BUILD FILE NOT FOUND");
                return 1;
            }
			
			system("./build");
            if (strcmpx(argv[1], "run"))
                system("./build && ./main");
        #else
            if (!io_file_exists("build.bat")) {
                puts("[ERROR] BUILD FILE NOT FOUND");
                return 1;
            }

            system("build.bat");
            if (strcmpx(argv[1], "run"))
                system("build.bat && main.exe");
        #endif
    }
    else if(strcmpx(argv[1], "list")) {
        #ifdef __unix__
            system("ls " TEMPLATES_PATH);
        #else
            system("dir " TEMPLATES_PATH);
        #endif
    }

    return 0;
}
