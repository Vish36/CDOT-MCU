pipeline {
    agent {
        docker { 
            image 'compilationenv:14.04' 
            args '-u root:sudo'
            
        }
        
    }
    stages {
        stage('gitcheckout') {
            steps {
                git credentialsId: '369ceaa2-ee83-481c-96e4-f47511dcc234', url: 'https://github.com/Vish36/CDOT-MCU.git'
            }
        }
        stage('Test') {
            steps {
                sh 'tar -xvf ./conference/dependencies/nasm-2.13.01.tar.xz'
                sh '''cd nasm-2.13.01/
                        ./configure
                        make
                        make install
                    '''
                sh './conference/build-cdotmcu'
            }
        }
        stage('stash'){
            steps{
                stash includes: './conference/CDOT-MCU/CDOT-MCU.tar', name: 'builtSources'
                 dir('/opt/') {
                unstash 'builtSources'
                 }
            }
        }
    }
}
