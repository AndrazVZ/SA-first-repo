#!/bin/bash

if [ -f ../main.c ]; then
	echo "main.c najden!"
	exit 0
else 
	echo "main.c ni najden!"
	exit 1
fi
