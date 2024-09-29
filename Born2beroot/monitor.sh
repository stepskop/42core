#!/bin/bash

cpus=$(grep "^physical id" /proc/cpuinfo | sort | uniq | wc -l)
cores=$(grep "^processor" /proc/cpuinfo | wc -l)
tram=$(free -m | awk '$1 == "Mem:" {print $2}')
uram=$(free -m | awk '$1 == "Mem:" {print $3}')
pram=$(awk "BEGIN {printf \"%.2f\", ($uram/$tram) * 100}")
tdisk=$(df -BG | grep "^/dev" | grep -v "/boot" | awk '{size += $2} END {print size}')
udiskm=$(df -BM | grep "^/dev" | grep -v "/boot" | awk '{size += $3} END {print size}')
tdiskm=$(df -BM | grep "^/dev" | grep -v "/boot" | awk '{size += $2} END {print size}')
pdisk=$(awk "BEGIN {printf \"%.2f\", ($udiskm/$tdiskm) * 100}")
cpuu=$(top -bn2 -d 0.01 | grep Cpu | tail -n 1 | awk '{printf("%.1f%%\n"), $2 + $4}')
boot=$(who -b | awk '$1 == "system" {print $3 " " $4}')
lvm=$(if [$(lsblk | awk '{print $6}' | grep "lvm" | wc -l) -eq 0]; then echo no; else echo yes; fi)
wall "	#Architecture: $(uname -a)
	#CPU physical: $cpus
	#vCPU: $cores
	#Memory Usage: $uram/${tram}MB ($pram%)
	#Disk Usage: $udiskm/${tdisk}Gb ($pdisk%)
	#CPU load: $cpuu
	#Last boot: $boot
	#LVM use: $lvm
	#Connections TCP : $(ss -t -H state established | wc -l) ESTABLISHED
	#User log: $(users | wc -w)
	#Network: IP $(hostname -I)($(cat /sys/class/net/enp0s3/address))
	#Sudo: $(journalctl _COMM=sudo | grep COMMAND | wc -l) cmd"
