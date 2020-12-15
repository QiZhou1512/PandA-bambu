#!/bin/bash
$(dirname $0)/../../etc/scripts/test_panda.py gcc_regression_simple --tool=bambu \
   --args="--configuration-name=CLANG10_O0 -O0 -lm --simulate --experimental-setup=BAMBU --compiler=I386_CLANG10" \
   --args="--configuration-name=CLANG10_O1 -O1 -lm --simulate --experimental-setup=BAMBU --compiler=I386_CLANG10" \
   --args="--configuration-name=CLANG10_O2 -O2 -lm --simulate --experimental-setup=BAMBU --compiler=I386_CLANG10" \
   --args="--configuration-name=CLANG10_O3 -O3 -lm --simulate --experimental-setup=BAMBU --compiler=I386_CLANG10" \
   -o output_clang10_simple -b$(dirname $0) --table=output_clang10_simple.tex --name="Clang10RegressionSimple" $@
exit $?
