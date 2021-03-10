
Debian
====================
This directory contains files used to package zurcoind/zurcoin-qt
for Debian-based Linux systems. If you compile zurcoind/zurcoin-qt yourself, there are some useful files here.

## zurcoin: URI support ##


zurcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install zurcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your zurcoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/bitcoin128.png` to `/usr/share/pixmaps`

zurcoin-qt.protocol (KDE)

