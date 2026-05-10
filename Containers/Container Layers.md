Different images share similar files (like Rails app and Django app share Ubuntu) to save disk space.

A layer = a directory with an ID (sha256 of the layer's content) and we list them with `ls <id>`

Writes go to a temporary layer.