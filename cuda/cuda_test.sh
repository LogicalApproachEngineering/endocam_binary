#!/bin/bash
sudo make
sudo mv libnvsample_cudaprocess.so /usr/lib/aarch64-linux-gnu/
gst-launch-1.0 v4l2src name=src device=/dev/video0 do-timestamp=true ! nvvidconv ! 'video/x-raw(memory:NVMM), format=(string)NV12', width=400, height=400 ! nvivafilter post-process=true customer-lib-name="libnvsample_cudaprocess.so" ! 'video/x-raw(memory:NVMM), format=(string)RGBA' ! nvvidconv flip-method=0 ! nvjpegenc ! image/jpeg, width=400, height=400, framerate=30/1 ! tee name=t ! queue ! nvjpegdec ! tee name=rawtee ! valve name=live_valve ! queue ! nvoverlaysink overlay=1 overlay-depth=1 overlay-x=326 overlay-y=31 overlay-w=682 overlay-h=657 sync=false name=sink t. ! queue name=queue_capture  ! videorate ! image/jpeg, framerate=2/1 ! appsink name=app_sink
