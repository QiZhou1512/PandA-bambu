#!/bin/bash
abs_script=$(readlink -e $0)
dir_script=$(dirname $abs_script)
$dir_script/xc7z020-1clg484-VVD_15.0_O2_sdc_aligned_accessClang4.sh $@
return_value=$?
if test $return_value != 0; then
   exit $return_value
fi
$dir_script/xc7z020-1clg484-VVD_15.0_O2_sdc_aligned_accessClang5.sh $@
return_value=$?
if test $return_value != 0; then
   exit $return_value
fi
$dir_script/xc7z020-1clg484-VVD_15.0_O2_sdc_aligned_accessClang6.sh $@
return_value=$?
if test $return_value != 0; then
   exit $return_value
fi
$dir_script/xc7z020-1clg484-VVD_15.0_O2_sdc_aligned_accessClang7.sh $@
return_value=$?
if test $return_value != 0; then
   exit $return_value
fi
$dir_script/xc7z020-1clg484-VVD_15.0_O2_sdc_aligned_accessGCC5.sh $@
return_value=$?
if test $return_value != 0; then
   exit $return_value
fi
$dir_script/xc7z020-1clg484-VVD_15.0_O2_sdc_aligned_accessGCC6.sh $@
return_value=$?
if test $return_value != 0; then
   exit $return_value
fi
$dir_script/xc7z020-1clg484-VVD_15.0_O2_sdc_aligned_accessGCC7.sh $@
return_value=$?
if test $return_value != 0; then
   exit $return_value
fi
$dir_script/xc7z020-1clg484-VVD_15.0_O2_sdc_aligned_accessGCC8.sh $@
return_value=$?
if test $return_value != 0; then
   exit $return_value
fi
exit 0


