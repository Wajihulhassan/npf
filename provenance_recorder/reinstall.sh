#!/bin/bash

make clean
make snap_provd
setfattr -n security.provenance -v "opaque" ./snap_provd

killall -9 snap_provd
cp snap_provd /usr/bin/snap_provd

./snap_provd /sys/kernel/debug/provenance0