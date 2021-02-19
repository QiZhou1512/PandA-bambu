#!/bin/bash
$(dirname $0)/../../etc/scripts/test_panda.py gcc_regression_simple --tool=bambu \
   --args="--configuration-name=CLANG11_O0 -O0 -lm --simulate --experimental-setup=BAMBU --compiler=I386_CLANG11" \
   --args="--configuration-name=CLANG11_O1 -O1 -lm --simulate --experimental-setup=BAMBU --compiler=I386_CLANG11" \
   --args="--configuration-name=CLANG11_O2 -O2 -lm --simulate --experimental-setup=BAMBU --compiler=I386_CLANG11" \
   --args="--configuration-name=CLANG11_O3 -O3 -lm --simulate --experimental-setup=BAMBU --compiler=I386_CLANG11" \
   -o output_clang11_simple -b$(dirname $0) --table=output_clang11_simple.tex --name="Clang11RegressionSimple" $@
exit $?