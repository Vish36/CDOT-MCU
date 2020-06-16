FROM ubuntu:14.04


#run during the build 
RUN apt-get update && echo "root:x:0:0:root:/root:/bin/bash >>/etc/passwd"
#Once container starts
CMD ["echo", "Hello container is up"]

