pipeline {
    
    agent any
    stages {
        stage('gitcheckout')
        {
            steps
            {
                retry(3)
                {
                    git credentialsId: '369ceaa2-ee83-481c-96e4-f47511dcc234', url: 'https://github.com/Vish36/CDOT-MCU.git'
                    //git credentialsId: '369ceaa2-ee83-481c-96e4-f47511dcc234', url: 'https://github.com/Vish36/jenkins-stash.git'
                }
            }
        }
        stage('env-preparation')
        {
            steps
            {
                script
                {
                    
                    docker.build("compilationenv:14.04","-f Dockerfile-comp_env .") //need docker registry currently using local docker ecosystem

                }
            }
             
        }
        stage('build') {
            agent {
                 docker { 
                    image 'compilationenv:14.04' 
                    args '-u root:sudo'
                 }
            
            }
            steps {
                retry(3)
                {
                    git credentialsId: '369ceaa2-ee83-481c-96e4-f47511dcc234', url: 'https://github.com/Vish36/CDOT-MCU.git'
                    //git credentialsId: '369ceaa2-ee83-481c-96e4-f47511dcc234', url: 'https://github.com/Vish36/jenkins-stash.git'
                }
                
                sh 'tar -xvf ./conference/dependencies/nasm-2.13.01.tar.xz'
                sh '''cd nasm-2.13.01/
                        ./configure
                        make
                        make install
                    '''
                    
                sh '''
                cd conference
                ./build-cdotmcu
                '''
                

                //echo "In compenv: Assume build is done"
                //sh 'ls -lrt '
              
               stash includes: 'conference/CDOT-MCU.tar' , name: 'CDOT-MCU_del'
               
               
            }
        }
     
        stage('create-cdotmcuImage')
        {
           
            steps
            {
                dir('Target')
                {
                    unstash 'CDOT-MCU_del'
                }
                script
                {
                    
                    docker.build("cdotmcu:1.0","-f Dockerfile-cdotmcu .")

                }
               
	        }
        }
        stage('testing')
        {
            steps
            {
                sh 'docker run -d cdotmcu:1.0'
            }
        }
    }
}
