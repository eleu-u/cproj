# about
cproj essentially works as a more convinient way to copy folders from a "templates" folder, which all include a build shell script which is used by cproj

if you actually compile this, make sure to change the TEMPLATES_PATH macro in main.c

# usage

create new projects with the "cproj new" command, this basically copies a folder from the templates path and renames them

new project example:

```sh
cproj new hello_world cpp 
```

#

build projects with the "cproj build" command, this literally only runs the build/build.bat script that is in the current working directory

build example:
```sh
cproj build
```

#

run projects with the "cproj run" command, this runs the build shell script and then runs ./main/main.exe

run example:
```sh
cproj run
```

#

list templates with the "cproj list" command, this literally just runs ls/dir in the TEMPLATES_PATH

list example:
```sh
cproj list
```

example output:
```sh
c	   c-libcurl-win  cpp-sdl-win  c-raylib-win  go
c-concord  cpp		  cpp-win      c-win	     go-imgui
```
