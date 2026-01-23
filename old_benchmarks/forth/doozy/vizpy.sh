#!/bin/sh

# fib_vanilla_noscope
/opt/opencilk-2/bin/clang -fopencilk -O3 -Og -g -fcilktool=cilkscale -o fvns_cs fib_vanilla_noscope.c
/opt/opencilk-2/bin/clang -fopencilk -O3 -Og -g -fcilktool=cilkscale-benchmark -o fvns_bench fib_vanilla_noscope.c

python3 /opt/opencilk-2/share/Cilkscale_vis/cilkscale.py -c ./fvns_cs -b ./fvns_bench -ocsv fvns.csv -oplot fvns.pdf

rm fvns_cs
rm fvns_bench

# fib_vanilla_scope

/opt/opencilk-2/bin/clang -fopencilk -O3 -Og -g -fcilktool=cilkscale -o fvs_cs fib_vanilla_scope.c
/opt/opencilk-2/bin/clang -fopencilk -O3 -Og -g -fcilktool=cilkscale-benchmark -o fvs_bench fib_vanilla_scope.c

python3 /opt/opencilk-2/share/Cilkscale_vis/cilkscale.py -c ./fvs_cs -b ./fvs_bench -ocsv fvs.csv -oplot fvs.pdf

rm fvs_cs
rm fvs_bench

# fib_cilkfor

/opt/opencilk-2/bin/clang -fopencilk -O3 -Og -g -fcilktool=cilkscale -o fcf_cs fib_cilkfor.c
/opt/opencilk-2/bin/clang -fopencilk -O3 -Og -g -fcilktool=cilkscale-benchmark -o fcf_bench fib_cilkfor.c

python3 /opt/opencilk-2/share/Cilkscale_vis/cilkscale.py -c ./fcf_cs -b ./fcf_bench -ocsv fcf.csv -oplot fcf.pdf

rm fcf_cs
rm fcf_bench

# doozy_noprint

/opt/opencilk-2/bin/clang -fopencilk -O3 -Og -g -fcilktool=cilkscale -o npdz_cs doozy_noprint.c
/opt/opencilk-2/bin/clang -fopencilk -O3 -Og -g -fcilktool=cilkscale-benchmark -o npdz_bench doozy_noprint.c

python3 /opt/opencilk-2/share/Cilkscale_vis/cilkscale.py -c ./npdz_cs -b ./npdz_bench -ocsv npdz.csv -oplot npdz.pdf

rm npdz_cs
rm npdz_bench

# doozy_reduce_noprint

/opt/opencilk-2/bin/clang -fopencilk -O3 -Og -g -fcilktool=cilkscale -o nprdz_cs doozy_reduce_noprint.c
/opt/opencilk-2/bin/clang -fopencilk -O3 -Og -g -fcilktool=cilkscale-benchmark -o nprdz_bench doozy_reduce_noprint.c

python3 /opt/opencilk-2/share/Cilkscale_vis/cilkscale.py -c ./nprdz_cs -b ./nprdz_bench -ocsv nprdz.csv -oplot nprdz.pdf

rm nprdz_cs
rm nprdz_bench
