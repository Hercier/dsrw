make all
for cnt in {1..4}
do
    echo doing testcase $cnt
    out=testcase/0/$cnt.out
    in=testcase/0/$cnt.in
    echo $out
    ./main <$in >a.out
    if diff $out a.out; then
        echo "AC"
    else
        echo "Failed!"
    fi
done
make clean