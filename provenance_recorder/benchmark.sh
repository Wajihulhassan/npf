#!/bin/bash

PID=$1
OUTFILE="/tmp/lpm_snap_log_size.plot"

echo "" > $OUTFILE

START_TIME=`date +%s%N | cut -b1-13`

while :
do
    line=`sudo pmap -x $PID | grep "total kB"`
    # Get size of process in KB
    size=`echo $line | awk '{print $3}'`
    # Get time in milliseconds
    CURR_TIME=`date +%s%N | cut -b1-13`
    DURATION=`expr $CURR_TIME - $START_TIME`
    GROWTH=`expr $size - 18660`
    echo $DURATION $GROWTH 
    echo $DURATION $GROWTH >> $OUTFILE 
    sleep 0.5
done
