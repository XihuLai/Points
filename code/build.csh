#!/bin/csh

if ( $#argv != 1 ) then
    echo "Wrong, need a file name"
    exit
endif

if ( $#argv == 1 && $1 == "-h" ) then
    echo "Usage : $0 file_name"
    exit
endif

set CC = g++

if ( ! -f $1 ) then
    echo "$1 not exit" 
else
    set fl = (`echo $1 | tr . ' '`)  
    #echo $fl[2]
    if ( "cpp" == $fl[2] ) then
        echo "-cpp build"
        $CC -o $fl[1].out $1
    else 
        if ( "java" == $fl[2] ) then
            echo "-java build"
            set CC = "javac"
            $CC $1
        else 
            echo "-c build"
            set CC = "gcc"
            $CC -o $fl[1].out $1
        endif
    endif
endif
