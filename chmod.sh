#! /bin/bash

#fix *.h files
find . -name '*.h' -not -path './.git/*' -exec chmod 644 {} \;

#fix *.c files
find . -name '*.c' -not -path './.git/*' -exec chmod 644 {} \;

#fix *.cpp files
find . -name '*.cpp' -not -path './.git/*' -exec chmod 644 {} \;

#fix *.hpp files
find . -name '*.hpp' -not -path './.git/*' -exec chmod 644 {} \;

#fix *.java files
find . -name '*.java' -not -path './.git/*' -exec chmod 644 {} \;

#fix *.py files
find . -name '*.py' -not -path './.git/*' -exec chmod 644 {} \;

#fix *.htmp files
find . -name '*.html' -not -path './.git/*' -exec chmod 644 {} \;

#fix *.conf files
find . -name '*.conf' -not -path './.git/*' -exec chmod 644 {} \;

#fix *.sample files
find . -name '*.sample' -not -path './.git/*' -exec chmod 644 {} \;

#fix *.tex files
find . -name '*.tex' -not -path './.git/*' -exec chmod 644 {} \;

#fix *.otf files
find . -name '*.otf' -not -path './.git/*' -exec chmod 644 {} \;

#fix .gitignore 
chmod 644 .gitignore

#fix README.md
chmod 644 README.md

#fix gadd.sh
chmod 644 gadd.sh

#fix chmod.sh
chmod 644 chmod.sh
