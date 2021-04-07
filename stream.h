#! /bin/bash

echo "Setup for 24/7 stream on Youtube"
read -p "Enter Your Bitrate (eg: 1500): "  VBR
read -p "Enter Your FPS (eg: 24): "  FPS
echo "Quality is set to Superfast"
QUAL="superfast"

YOUTUBE_URL="rtmp://a.rtmp.youtube.com/live2"
read -s -p "Enter Your Stream Key: " KEY

read -p "Enter Your Video File Source: " VIDEO_SOURCE
read -p "Enter Your Audio File Source: " AUDIO_SOURCE

ffmpeg \
-re -fflags +genpts -f lavfi -stream_loop -1 -i "movie=filename=$VIDEO_SOURCE, setpts=N/(FRAME_RATE*TB)" \
-thread_queue_size 512 -i "$AUDIO_SOURCE" \
-map 0:v:0 -map 1:a:0 \
-map_metadata:g 1:g \
-vcodec libx264 -pix_fmt yuv420p -preset $QUAL -r $FPS -g $(($FPS * 2)) -b:v $VBR \
-acodec libmp3lame -ar 44100 -threads 6 -qscale:v 3 -b:a 320000 -bufsize 512k \
-f flv "$YOUTUBE_URL/$KEY"
