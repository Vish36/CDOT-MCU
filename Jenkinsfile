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
                    
                    docker.build("compilationenv:14.04","-f Dockerfile-comp_env .")

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
                

               stash includes: 'conference/CDOT-MCU.tar' , name: 'CDOT-MCU_del'
               
               
            }
        }
     
        stage('create-cdotmcuImage')
        {
           
            steps
            {
                dir('TARGET')
                {
                    unstash 'CDOT-MCU_del'
                }
               // sh 'docker build -t cdotmcu:1.0 -f Dockerfile-cdotmcu .'
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
                sh 'docker run -p 5060:5060 -p 1420:1420 -p 5061:5061 -d cdotmcu:1.0'
            }
        }
    }
}
