ldapsearch -Q "(sn=*bon*)" | grep "sn: " | wc -l | rev | cut -d ' ' -f 1 | rev
