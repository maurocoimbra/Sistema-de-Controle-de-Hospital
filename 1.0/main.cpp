#include <iostream>
#include <string.h>
#include "Paciente.h"

using namespace std;

void exibeMenu(){
    cout << endl << "Opcao 1 - Listar pacientes" << endl;
    cout << "Opcao 2 - Exibir Protuario" << endl;
    cout << "Opcao 3 - Atualizar Prontuario" << endl;
    cout << "Opcao 4 - Cadastrar Paciente" << endl;
    cout << "Opcao 5 - Remover Paciente" << endl;
    cout << "Opcao 6 - Sair" << endl << endl;
}

int main() {
    int opcao=3,nPacientes,flag; //Paciente precisa ser inicializado com algum valor valido
    string qualPaciente;
    nPacientes=4;
    Paciente paciente[99];

    paciente[0].setNome("Mauro Castro");
    paciente[0].setIdade(20);
    paciente[0].setSexo('M');
    paciente[0].setCpf("123.987.650-98");
    paciente[0].setSituacao("O paciente esta tomando soro");

    paciente[1].setNome("Ana Pereira");
    paciente[1].setIdade(32);
    paciente[1].setSexo('F');
    paciente[1].setCpf("765.384.658-36");
    paciente[1].setSituacao("Paciente acordou com enxaqueca");

    paciente[2].setNome("Carlos Pereira");
    paciente[2].setIdade(19);
    paciente[2].setSexo('M');
    paciente[2].setCpf("543.123.564-78");
    paciente[2].setSituacao("Paciente recebeu alta");

    paciente[3].setNome("Ana Leite");
    paciente[3].setIdade(12);
    paciente[3].setSexo('F');
    paciente[3].setCpf("543.123.564-78");
    paciente[3].setSituacao("Paciente anestesiada");

    /*Cadastro Inicial
    cout << "Informe a quantidade de pacientes a serem cadastrados: ";
    cin >> nPacientes;
    getchar();
    Paciente paciente[nPacientes];
    */

    /*Debug
    for(int i=0;i<nPacientes;i++)
        paciente[i].preencherCadastro();
    cout << "Qual paciente voce deseja exibir? ";
    cin >> qualpaciente;
    paciente[qualpaciente].exibePaciente();
    */

    //Menu
    do{
        if(opcao>=1 && opcao<=5)
            exibeMenu();
        cin >> opcao;
        getchar();
        switch (opcao){
            case 1:
                if(nPacientes==0){
                    cout << "Nao ha nenhum paciente, e necessario cadastrar algum antes" << endl;
                    break;
                }
                for(int i=0;i<nPacientes;i++)
                    cout << i+1 << " - " << paciente[i].getNome() << endl;
                break;
            case 2:
                cout << "Digite o nome do paciente que voce deseja exibir: ";
                getline(cin,qualPaciente);
                flag=0;
                for(int i=0;i<nPacientes;i++)
                    /*
                    if(strcasecmp(paciente[i].getNome().c_str(),qualPaciente.c_str())==0){
                        paciente[i].exibePaciente();
                        flag=1;
                        break;
                    */
                    if(paciente[i].getNome().find(qualPaciente) != string::npos){
                        paciente[i].exibePaciente();
                        flag=1;
                    }
                if(!flag)
                    cout << "Paciente nao encontrado" << endl;
                break;
            case 3:
                cout << "Digite o nome do paciente que voce deseja atualizar: ";
                getline(cin,qualPaciente);
                //getchar();
                flag=0;
                for(int i=0;i<nPacientes;i++)
                    if(paciente[i].getNome().find(qualPaciente) != string::npos){
                        paciente[i].atualizaSituacao();
                        flag=1;
                        break;
                    }
                if(!flag)
                    cout << "Paciente nao encontrado" << endl;
                break;
            case 4:
                nPacientes++;
                paciente[nPacientes-1].preencherCadastro();
                break;
            case 5:
                cout << "Informe o nome do paciente que sera removido: ";
                getline(cin,qualPaciente);
                flag=0;
                for(int i=0;i<nPacientes;i++){
                    if(paciente[i].getNome().find(qualPaciente) != string::npos){
                        flag=1;
                    }
                    if(flag && i != nPacientes-1){
                        paciente[i].setNome(paciente[i+1].getNome());
                        paciente[i].setIdade(paciente[i+1].getIdade());
                        paciente[i].setSexo(paciente[i+1].getSexo());
                        paciente[i].setCpf(paciente[i+1].getCpf());
                        paciente[i].setSituacao(paciente[i+1].getSituacao());
                    }
                }
                if(flag){
                    nPacientes--;
                    paciente[nPacientes].removeCadastro();
                }
                else
                    cout << "Paciente nao encontrado" << endl;
                break;
            case 6:
                cout << "Obrigado por usar nosso modelo de prontuario!!" << endl;
                break;
            default:
                    cout << "Numero invalido, digite outro numero: ";
                }
    }while(opcao!=6);
    return 0;
}
