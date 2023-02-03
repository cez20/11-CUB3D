#!/bin/bash
RED='\033[1;31m'
NC='\033[0m'

for file in $(ls mapfiles); do
        echo -e "${RED}$file${NC}"
        leaks -q --atExit -- ./so_long "mapfiles/$file"
		echo -e "__________________________________________\n"
done