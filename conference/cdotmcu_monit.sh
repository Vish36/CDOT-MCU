#!/bin/bash
USER=root
PROCC=cdot-mcu
BIN_PATH=/opt/CDOT-MCU/bin
while [ 1 ] 
do
PROC_PID=`ps -u "$USER" | \
          grep "$PROCC"      | \
          awk '{print $1}'`
#echo "PID inside the script is $PROC_PID"
if [ -z "$PROC_PID" ]; then
    $BIN_PATH/$PROCC  -x 
fi
sleep  8
done 
