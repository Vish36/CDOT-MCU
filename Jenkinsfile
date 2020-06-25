pipeline {
    
    agent any
    stages {
        stage('gitcheckout')
        {
            steps
            {
                retry(3)
                {
                    git credentialsId: '369ceaa2-ee83-481c-96e4-f47511dcc234', url: 'https://github.com/Vish36/jenkins-stash.git'
                }
            }
        }
        stage('env-preparation')
        {
             script
                {
                    
                    docker.build("compilationenv:14.04","-f Dockerfile-comp_env .")

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
                
                /*sh 'tar -xvf ./conference/dependencies/nasm-2.13.01.tar.xz'
                sh '''cd nasm-2.13.01/
                        ./configure
                        make
                        make install
                    '''
                sh './conference/build-cdotmcu'
                sh 'tar -xvf '
                */

                echo "In compenv: Assume build is done"
                sh 'ls -lrt '
              
               stash includes: 'main.c' , name: 'mainFile'
               
               
            }
        }
     
        stage('create-cdotmcuImage')
        {
           
            steps
            {
                dir('Target')
                {
                    unstash 'mainFile'
                }
                
                script
                {
                    
                    docker.build("cdotmcu:1.0","-f Dockerfile-cdotmcu .")

                }
               
	        }
        }
        stage('tesing')
        {
            steps
            {
                sh 'docker run -d cdotmcu:1.0'
            }
        }
    }
}
