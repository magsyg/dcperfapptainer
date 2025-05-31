#!/bin/sh
#SBATCH --partition=CPUQ
#SBATCH --account=share-ie-idi
#SBATCH --time=0-04:00:00     # 0 days and 15 minutes limit
#SBATCH --nodes=1             # 1 compute nodes
#SBATCH --cpus-per-task=8     # 2 CPU cores
#SBATCH --mem=48G              # 5 gigabytes memory
#SBATCH --output=./pyperf_results/313_pyperf_TL20t_6.txt    # Log file
#SBATCH --nodelist=idun-03-[01-48],idun-04-[01-36]
#SBATCH --exclusive
name='TL20t'
apptainer run --writable-tmpfs /cluster/home/magnuosy/Desktop/project/forprosjekt/DCPerf/313_pyperf$name.sif