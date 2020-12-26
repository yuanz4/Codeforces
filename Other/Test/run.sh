for ((i = 1; i <= 100; i++));
do
	echo "Test" $i
	./gen $i > in
	./code < in > out1
	./brute < in > out2
	if !(diff -w out1 out2 > /dev/null)
	then
		echo "--------------"
		echo "Fail the test:"
		cat in
		echo "Wrong:"
		cat out1
		echo "Corret:"
		cat out2
		break
	fi
done
