leaks --atExit -- ./cub3d mapfiles/invalid/01_norightsformaps
sleep 2
leaks --atExit -- ./cub3d mapfiles/invalid/02_noextension
sleep 2
leaks --atExit -- ./cub3d mapfiles/invalid/03_map.cab
sleep 2
leaks --atExit -- ./cub3d mapfiles/invalid/04_map.cu
sleep 2
leaks --atExit -- ./cub3d mapfiles/invalid/05_map.cube
sleep 2
leaks --atExit -- ./cub3d mapfiles/invalid/06_wrongextension.cub.ber
sleep 2
leaks --atExit -- ./cub3d mapfiles/invalid/07_empty.cub 