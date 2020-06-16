#!/bin/bash

TARFILE=CDOT-MCU.tar
conf_dir="/etc"
filePresence()
{
	if [ ! -f $1 ]
	then
		return 1 
	else
		return 0
	fi

}
amIRoot()
{
	#echo "Euid is $EUID"
	if [[ $EUID -ne 0 ]]; then
		echo "This script must be run as root" 1>&2
		exit 1;
	fi
}
isTarAvailable()
{
	
	if [ ! -f "$TARFILE" ]
        then
		echo "Deliverable $TARFILE is not present"	
		exit 1
	fi
}
untarDelv()
{
	tar -xvf $TARFILE
}
prerequisiteChanges()
{	
	echo hello	
}
install()
{
	cp -r ./opt/* /opt/
	cp ./opt/CDOT-MCU/cdotmcu /etc/init.d/
	chmod a+x /etc/init.d/cdotmcu
}
main()
{
	amIRoot
	isTarAvailable
	untarDelv
	install
	
	filePresence $conf_dir/security/limits.conf
	ret=$?
	if [[ $ret -ne 0 ]] ;then
		echo "File $conf_dir/security/limits.conf is not present exiting"
		exit 1
	fi

	configured=`grep "CDOT-MCU" ${conf_dir}/security/limits.conf|wc -l`
	if [ $configured -eq 0 ] ;then
	        echo -e "#CDOT-MCU CHANGES : START\n\
*  soft     nproc          65535 \n\
* hard     nproc          65535 \n\
* soft     nofile         65535 \n\
* hard     nofile         65535\n\
root soft     nproc          65535 \n\
root hard     nproc          65535\n\
root soft     nofile         65535\n\
root hard     nofile         65535\n#CDOT-MCU CHANGES : END" >>${conf_dir}/security/limits.conf 
	fi

	filePresence $conf_dir/sysctl.conf
        ret=$?
        if [[ $ret -ne 0 ]] ;then
                echo "File $conf_dir/sysctl.conf is not present exiting"
                exit 1
        fi

	configured=`grep "CDOT-MCU" ${conf_dir}/sysctl.conf|wc -l`
	if [ $configured -eq 0 ] ;then
	echo -e  "#CDOT-MCU CHANGES : START\n#This line is added to increase the number of file descriptor\n\
fs.file-max = 65535\n#CDOT-MCU CHANGES : END">>  $conf_dir/sysctl.conf
	fi


	filePresence $conf_dir/pam.d/common-session
        ret=$?
        if [[ $ret -ne 0 ]] ;then
                echo "File $conf_dir/pam.d/common-session is not present exiting"
                exit 1
        fi

        configured=`grep "CDOT-MCU" $conf_dir/pam.d/common-session|wc -l`
        if [ $configured -\eq 0 ] ;then
        echo -e  "#CDOT-MCU CHANGES : START\n#end of pam-auth-update config\nsession required pam_limits.so #CDOT-MCU CHANGES : END
">> $conf_dir/pam.d/common-session 
        fi
	rm -rf ./opt
	echo Installation finish successfully		

}

# vishnu please make chnages in build_cdotmcu  to create rel dir,copy /opt and installation scr in ./rel and make a tar

#Envoking main()
main
