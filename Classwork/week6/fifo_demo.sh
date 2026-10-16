mkfifo /tmp/d.fifo 
cat /tmp/d.fifo &

echo "Hello" > /tmp/d.fifo 
cat /tmp/d.fifo &

ls -l /tmp/d.fifo
rm /tmp/d.fifo