#!/bin/bash

sleep 1
request code_manager "0 master ARCH=x86 NAME=master sample param1 param2"

sleep 5 
cat log/code_manager.log

! grep -i error log/code_manager.log && \
    grep "Loading loader at" log/code_manager.log && \
    grep "No suitable loader for sample" log/code_manager.log && \
    grep "Got environment var: ARCH=x86" log/code_manager.log 

TEST_RESULT=$?