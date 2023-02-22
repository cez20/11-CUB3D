#!/bin/bash
RED='\033[1;31m'
NC='\033[0m'

for file in $(ls mapfiles); do
        echo -e "${RED}$file${NC}"
        leaks -q --atExit -- ./cub3d "mapfiles/$file"
		echo -e "__________________________________________\n"
done

for file in $(ls mapfiles/invalid); do
        echo -e "${RED}$file${NC}"
        leaks -q --atExit -- ./cub3d "mapfiles/invalid/$file"
		echo -e "__________________________________________\n"
done