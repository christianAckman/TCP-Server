#!/bin/bash

# Destination
# declare -r HOST="localhost"
# declare -r PORT="8080"

# Arguments
declare -r ARGS="$@"

function log_func(){
    echo "${1}"
}

function send_message(){
    log_func "${FUNCNAME[0]}"
    local -r HOST="${1}"
    local -r PORT="${2}"
    local -r MESSAGE="${3}"
    echo "${MESSAGE}" | nc "${HOST}" "${PORT}"
}

function check_args(){
    log_func "${FUNCNAME[0]}"
    if [ $# -ge 3 ]; then
        echo script has at least 3 arguments
    else
        echo "please run script like this: send.sh <host> <port> <message>"
        exit 0
    fi
}

function main(){
    log_func "${FUNCNAME[0]}"
    check_args
    send_message "${1}" "${2}" "${3}"
}
main $@
