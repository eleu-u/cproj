# about
cproj essentially works as a more convinient way to copy folders from a "templates" folder, which all include a build shell script which is used by cproj

cproj is meant to be cross-platform as some of this was written while i still used windows but i've changed a small amount of stuff so im not too sure if it'd work on windows (i havent tested it)

if you actually compile this for some reason, make sure to change the TEMPLATES_PATH macro in main.c

# usage

copies a folder from the templates path and renames it (if the template argument is not provided, "c" will be used)

example:

```sh
cproj new hello_world cpp 
```

#

runs the build/build.bat script that is in the current working directory

example:
```sh
cproj build
```

#

runs the build shell script and then runs ./main or main.exe

example:
```sh
cproj run
```

#

this literally just runs ls/dir in the TEMPLATES_PATH

example:
```sh
cproj list
```

example output:
```sh
c	   c-libcurl-win  cpp-sdl-win  c-raylib-win  go
c-concord  cpp		  cpp-win      c-win	     go-imgui
```
