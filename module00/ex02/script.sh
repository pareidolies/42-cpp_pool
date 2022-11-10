make
./account > result.log
awk '{print $2}' 19920104_091532.log > out1
awk '{print $2}' result.log > out2
diff out1 out2
rm result.log out1 out2
make fclean