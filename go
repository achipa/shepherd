cd shepherd
fakeroot qmake
make distclean
doxygen
rm *.o -f
rm moc_* -f
rm debian/shepherd.substvars
cd ..
dpkg-buildpackage -rfakeroot -I.svn -S -sa
