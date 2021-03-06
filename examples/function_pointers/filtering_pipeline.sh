#!/bin/bash
#   --args="-v4 --configuration-name=default-ALLBRAM-treevectorize --evaluation --compiler=I386_GCC49 --memory-allocation-policy=ALL_BRAM -ftree-vectorize" \
`dirname $0`/../../etc/scripts/test_panda.py -l list_pipeline --tool=bambu \
   --args="-v4 --configuration-name=default --compiler=I386_GCC49 --experimental-setup=BAMBU" \
   -o output_filtering_pipeline -b`dirname $0` --table=filtering_pipeline.tex --stop --name="FilteringPipeline" $@
return_value=$?
if test $return_value != 0; then
   exit $return_value
fi

