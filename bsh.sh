#!/bin/bash
while IFS='' read -r line || [[ -n "$line" ]]; do
    #echo "Text read from file: $line"
    IFS=', ' read -r -a array <<< "$line"
    for element in "${array[@]}"
    do
        #echo "$element" # do whatever you want to do with this value
        echo $((element+1))
    done
done < "$1"
