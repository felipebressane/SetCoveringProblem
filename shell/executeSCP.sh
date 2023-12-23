


#for ((x=5; x<13; x++)); do
for ((x=10; x<13; x++)); do
#	for arq in $(cat lista1.txt); do
	for arq in $(cat lista2.txt); do
	   ./scp.sh $arq $x
	done
done	
