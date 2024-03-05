#!/bin/bash

function run {
  if ! pgrep $1 ;
  then
    $@&
  fi
}

# Applications to autostart go in here
run picom
run /usr/bin/emacs --daemon
run xhost +SI:localuser:$USER
#run nm-applet
#run caffeine
#run pamac-tray
#run variety
#run xfce4-power-manager
#run blueberry-tray
#run /usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1
#run numlockx on
#run volumeicon
#run dropbox
#run insync start
#run spotify
#run ckb-next -b
#run discord
run betterlockscreen -u Pictures/Wallpapers/ # Get new image for lockscreen
