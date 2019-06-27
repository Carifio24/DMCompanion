echo ${1}
echo ${2}
var1=`find . -type f -iname '*${1}*'`
for i in ${var1}; do echo ${i}; done
#for i in $var1; do mv "$i" "`echo $i | sed 's/${1}/${2}/g'`"; done