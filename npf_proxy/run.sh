#!/bin/bash

killall -9 proxy
killall -9 sqlprov
make clean
make

#postgres
#./proxy  -l 54320 -h 127.0.0.1 -p 5432
#mysql
./proxy  -l 3306 -h 127.0.0.1 -p 33060