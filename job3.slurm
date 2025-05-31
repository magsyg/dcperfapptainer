#!/bin/sh
#SBATCH --partition=CPUQ
#SBATCH --account=share-ie-idi
#SBATCH --time=0-4:00:00     # 0 days and 15 minutes limit
#SBATCH --nodes=1             # 1 compute nodes
#SBATCH --cpus-per-task=16     # 2 CPU cores
#SBATCH --mem=48G              # 5 gigabytes memory
#SBATCH --output=313pyperfopcodecounts.txt    # Log file


apptainer run --writable-tmpfs 313_pyperfcounting.sif
