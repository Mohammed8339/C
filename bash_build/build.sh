#!/bin/sh
umask 022

VERSION_NUMBER="1.1"

update() {
        curl -o updated.sh "https://raw.githubusercontent.com/MohammedAlAkashi/C/main/bash_build/build.sh"
        mv updated.sh "$0"
        chmod +x "$0"
        echo "updated successfully... run with -h for help."
        exit 0
}


if [ $# -lt 1 ]; then
    echo "missing 1 argument(s)"
    echo "build C_FILE OUTPUT_NAME - OPTIONAL"
    echo "exited with status code 2"
    exit 2
fi

if [ "$1" = "-u" ]; then
        echo "checking for updates..."
        version=$(curl "https://raw.githubusercontent.com/MohammedAlAkashi/C/main/bash_build/version.txt" 2> /dev/null )

        if [ "$version" != "$VERSION_NUMBER" ]; then
                echo "updating..."
                update
                exit 0
        else
                echo "already up to date."
                exit 0
        fi

        exit 0
fi

if [ "$1" = "-s" ]; then
    echo 'alias build="~/build.sh"' >> ~/.bashrc
    source ~/.bashrc
    echo 'success, type "build -h" for details'
    exit 0
fi

if [ "$1" = "-h" ]; then
        echo "----- HELP -----"
        echo ""
        echo "build FILE.c"
        echo ""
        echo "--- OPTIONAL ---"
        echo ""
        echo "build FILE.c OUTPUT_NAME"
        echo "ex: build main.c output"

    exit 0
fi

if [ $# -eq 1 ]; then
    gcc -g -o output "$1" -ansi -pedantic -Wall
elif [ $# -ge 2 ]; then
    gcc -g -o "$2" "$1" -ansi -pedantic -Wall
fi

result=$?

if [ $result -eq 0 ]; then
        echo "build successful with exit code: $result"
        exit 0
else
        echo "build failed with exit code: $result"
        exit 1
fi
