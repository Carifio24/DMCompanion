#!/bin/bash

for file in *${1}*
do
    dst=${file/${1}/${2}}
    if ! [[ ${dst} == ${file} ]]
    then
        mv ${file} ${dst}
    fi
done