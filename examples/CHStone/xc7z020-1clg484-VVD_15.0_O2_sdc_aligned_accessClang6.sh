#!/bin/bash
ARGS="-c=--clock-period=15 -c=--simulator=VERILATOR -c=-v4 -c=--speculative-sdc-scheduling -c=--experimental-setup=BAMBU-BALANCED-MP -c=--device=xc7z020-1clg484-VVD -c=--aligned-access -c=--compiler=I386_CLANG6 -c=--debug-classes=structural_objects"
script=$(readlink -e $0)
root_dir=$(dirname $script)
NAME=$(basename $0 .sh)
DIRNAME=${root_dir##*/}
$root_dir/xilinx.sh $ARGS -ooutput_${DIRNAME}_$NAME --name=${DIRNAME}_$NAME --table=${DIRNAME}_$NAME.tex $@
return_value=$?
if test $return_value != 0; then
   exit $return_value
fi
exit 0
