FROM ubuntu:14.04


#run during the build 
RUN apt-get update && apt-get -y install build-essential git flex bison autoconf automake pkg-config md5deep libtool libssl-dev  libfreetype6-dev libavformat-dev
#Once container starts
CMD ["echo", "Hello container is up"]

