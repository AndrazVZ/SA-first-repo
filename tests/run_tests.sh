#!/bin/bash

if [ -f main.cpp ]; then
	echo "main.cpp najden!"
	exit 0
else 
	echo "main.cpp ni najden!"
	exit 1
fi
