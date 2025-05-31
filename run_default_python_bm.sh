#!/bin/bash
#SBATCH --job-name="run-python-computed-benchmarks-django"
#SBATCH --account=share-ie-idi
#SBATCH --nodes=1
#SBATCH -c8
#SBATCH --mem-per-cpu=8G
#SBATCH --time=0-01:30:00
#SBATCH --mail-user=magnuosy@ntnu.no
#SBATCH --mail-type=ALL


for i in $(seq 1 10)
do
    srun --account=share-ie-idi -J num-collection-$i-wcg-msy --mail-user=magnuosy@ntnu.no --mail-type=FAIL --mem-per-cpu=10G -n1 -c8 --time=90  perf stat -e instructions,cycles,branch-misses,branch-instructions,cache-misses,cache-references,context-switches,major-faults,L1-dcache-load-misses,L1-icache-load-misses,LLC-load-misses,LLC-store-misses,dTLB-load-misses,dTLB-store-misses,iTLB-load-misses apptainer run --writable-tmpfs /cluster/home/magnuosy/Desktop/project/forprosjekt/DCPerf/wcg/DjangWCG.sif
    #srun --account=share-ie-idi -J num-collection-$i-ncg-msy --mail-user=magnuosy@ntnu.no --mail-type=FAIL --mem-per-cpu=20G -n1 -c8 --time=90 perf stat -e instructions,cycles,branch-misses,branch-instructions,cache-misses,cache-references,context-switches,major-faults,L1-dcache-load-misses,L1-icache-load-misses,LLC-load-misses,LLC-store-misses,dTLB-load-misses,dTLB-store-misses,iTLB-load-misses apptainer run --writable-tmpfs /cluster/home/magnuosy/Desktop/project/forprosjekt/DCPerf/ncg/DjangNCG.sif >& /cluster/home/magnuosy/Desktop/project/forprosjekt/DCPerf/ncg/resultsNCG$i.txt
done

#    # IPC-1 Benchmarks
#    srun --account=share-ie-idi -J num-collection-$(basename ${bin}) 
#    --mail-user=magnuosy@ntnu.no --mail-type=FAIL --mem-per-cpu=50G -n1 -c8 -t$timelimit -o 
#    /cluster/work/romankb/latency-spec-$(basename ${bin})-%j.out    
#    -e /cluster/work/romankb/latency-spec-$(basename ${bin})-%j.err    
#    python ~/ChampSim/data_collector.py --warmup 30000000 --evaluation 30000000 --experiment_executable ${bin} 
#    --traces_directory /cluster/work/romankb/dataset/IPC1_new_translated/spec   
#    --nosub --output_dir /cluster/work/romankb/results/${dir}_${count}/ipc1_spec/sizes_$(basename ${bin})/      
#    &>> /cluster/work/romankb/pyrunner_latency_fixed_ipc1_spec_$(basename ${bin}).log &
for job in `jobs -p`
do
    echo $job
    wait $job
done