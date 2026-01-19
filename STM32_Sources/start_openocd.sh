#!/bin/bash
# Kill old OpenOCD
killall openocd 2>/dev/null
# Start OpenOCD in background
/opt/homebrew/bin/openocd -f openocd.cfg &
# Wait for it to start
sleep 2
