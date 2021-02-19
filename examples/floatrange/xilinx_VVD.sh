#!/bin/bash
ARGS="-c=--no-iob -c=--soft-float -c=--softfloat-norounding -c=-lm -c=--hls-div -c=--registered-inputs=top -c=--panda-parameter=profile-top=1 -c=--device=TO_BE_OVERWRITTEN -c=--evaluation"
$(dirname $0)/../../etc/scripts/test_panda.py --spider-style="../lib/latex_format_bambu_results_xilinx.xml" --tool=bambu -l$(dirname $0)/floatrange_list -ofloatrange_xilinx $ARGS -t120m --table=floatrange_xilinx.tex --benchmarks_root=$(dirname $0) $@
return_value=$?
if test $return_value != 0; then
   exit $return_value
fi
exit 0