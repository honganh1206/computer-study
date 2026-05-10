A container image is a *tarball of a filesystem* (or several tarballs, 0 per layer)

Build: Start with base OS -> Install programs + dependencies -> Configure -> Make a tarball of the whole filesystem

Run: Download tarball -> unpack to  a directory -> run program that pretends directory is the whole filesystem
