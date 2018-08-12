#!/usr/bash/bin
g++ $1 -o temp >> log
if [[ ! -s log ]]
    then
    echo '运行成功\n'
    ./temp
else   
    echo '运行失败\n'
    cat log
if

