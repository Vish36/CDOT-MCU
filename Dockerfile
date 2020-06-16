FROM ubuntu:14.04


#run during the build 
RUN apt-get update
ADD CDOT-MCU /opt/CDOT-MCU
#Once container starts
CMD ["echo", "Hello vish...! my first container is starting"]

