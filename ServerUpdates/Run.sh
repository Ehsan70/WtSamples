#!/bin/sh

# Maybe this has to be sudo . Not sure. 
sudo ./main --docroot . --http-address 0.0.0.0 --http-port 9090

exit $?
