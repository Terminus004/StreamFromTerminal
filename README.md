# StreamFromTerminal
Cost effective way to stream your music 24/7 on Youtube without using OBS UI and GPU, on Ubuntu server
- First start by gathering your own stream key from Youtube Studio
- Connect to your VPS and start a screen session 
```
screen -S stream
```
if you haven't installed screen and ffmpeg install by using this command
```
sudo apt install screen ffmpeg
```
clone this repo

```
git clone https://github.com/Terminus004/StreamFromTerminal.git && cd StreamFromTerminal
```
Now change permissions for the file
```
chmod +x stream.sh
```
Now you can run the file
```
./stream.sh
```
Fill all the details asked and enjoy your stream

Now to come out of screen session press Ctrl+a d

To close the stream press Ctrl+C

Disconnect from VPS the process will run in background 

If you want to revisit screen session
```
screen -r stream
```
Thanks for your Interest just give a star if you like it, if you don't suggest changes :)
