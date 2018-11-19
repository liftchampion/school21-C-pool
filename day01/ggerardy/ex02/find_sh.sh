find . -type f -name "*.sh" | rev | cut -c 4- | cut -d '/' -f 1 | rev
