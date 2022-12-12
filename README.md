# about
cproj essentially works as a more convinient way to copy folders from a "templates" folder, which all include a build shell script which is used by cproj

cproj is meant to be cross-platform as some of this was written while i still used winodws but i've changed a small amount of stuff so im not too sure if it'd work on windows (i havent tested it)

if you actually compile this, make sure to change the TEMPLATES_PATH macro in main.c

# usage

copies a folder from the templates path and renames it

new project example:

```sh
cproj new hello_world cpp 
```

#

runs the build/build.bat script that is in the current working directory

build example:
```sh
cproj build
```

#

runs the build shell script and then runs ./main or main.exe

run example:
```sh
cproj run
```

#

this literally just runs ls/dir in the TEMPLATES_PATH

list example:
```sh
cproj list
```

example output:
```sh
c	   c-libcurl-win  cpp-sdl-win  c-raylib-win  go
c-concord  cpp		  cpp-win      c-win	     go-imgui
```
