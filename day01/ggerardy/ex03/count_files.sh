find . \( -type f -o -type d \) | wc -l | rev | cut -d ' ' -f 1 | rev
