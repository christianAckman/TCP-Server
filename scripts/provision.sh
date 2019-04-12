#!/bin/bash

function log_func(){
    echo "${1}"
}

function main(){
    log_func "${FUNCNAME[0]}"
}
main