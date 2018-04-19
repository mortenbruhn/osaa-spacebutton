#!/bin/bash
CMD=/usr/bin/pcb2gcode

prefix=$1

if [ -z "${prefix}" ]
then
	echo "No prefix given, exiting."
	exit 1
fi

backfile="${prefix}-B.Cu.gbr"
drillfile="${prefix}.drl"

if [ -f "${backfile}" ] && [ -r "${backfile}" ] 
then
	echo "Backfile found: ${backfile}"
else
	echo "No backfile found, exiting"
	exit 1
fi

if [ -f "${drillfile}" ] && [ -r "${drillfile}" ] 
then
	echo "Drillfile found: ${drillfile}"
else
	echo "No drillfile found"
fi

echo "Generating G-code"
${CMD} \
	--back ${backfile} \
	--drill ${drillfile} \
	--basename ${prefix} \
	--metric \
	--zsafe 10 \
	--zwork -0.035 \
	--mill-feed 200 \
	--mill-speed 10000 \
	--zchange 30 \
	--offset 0.25 \
	--zdrill -4 \
	--drill-feed 200 \
	--drill-speed 12000
