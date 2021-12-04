#include <iostream>
#include <string.h>
#include <fstream>

#include "Paciente.h"
#include "Funcionario.h"

using namespace std;
using namespace dados;

void exibeMenuGeral(){
    cout << "Informe com qual menu voce deseja interagir" << endl;
    cout << "Opcao 1 - Funcionarios" << endl;
    cout << "Opcao 2 - Pacientes" << endl;
    cout << "Opcao 3 - Sair" << endl;
}

void exibeMenuFuncionario(){
    cout << endl << "Opcao 1 - Listar Funcionarios" << endl;
    cout << "Opcao 2 - Exibir Cadastro" << endl;
    cout << "Opcao 3 - Atualizar Cadastro" << endl;
    cout << "Opcao 4 - Cadastrar Funcionario" << endl;
    cout << "Opcao 5 - Remover Funcionario" << endl;
    cout << "Opcao 6 - Sair" << endl << endl;
}

void exibeMenuPaciente(){
    cout << endl << "Opcao 1 - Listar Pacientes" << endl;
    cout << "Opcao 2 - Exibir Prontuario" << endl;
    cout << "Opcao 3 - Atualizar Prontuario" << endl;
    cout << "Opcao 4 - Cadastrar Paciente" << endl;
    cout << "Opcao 5 - Remover Paciente" << endl;
    cout << "Opcao 6 - Sair" << endl << endl;
}

int main() {
    int opcaoGeral = 1, opcao = 3, nPacientes = 0, nFuncionarios = 0, flag, tipo;
    string qualPessoa;
    Endereco endereco;
    Pessoa *pessoa[2][99];
    ifstream leituraFuncionarios, leituraPacientes;
    ofstream escreveFuncionarios, escrevePacientes;

    //Leitura dos Funcionarios
    string nome, cpf, cargo, rua, bairro;
    int numero;
    float salario;

    leituraFuncionarios.open("Funcionarios.txt", ios::in);
    if(!leituraFuncionarios.is_open())
        cout << "Erro ao abrir Funcionarios.txt\n";

    while(!leituraFuncionarios.eof() && !leituraFuncionarios.fail()){
        try{
            getline(leituraFuncionarios, nome);
            //cout << nome << endl;
            getline(leituraFuncionarios, cpf);
            //cout << cpf << endl;
            getline(leituraFuncionarios, cargo);
            //cout << cargo << endl;
            leituraFuncionarios >> salario;
            if(leituraFuncionarios.fail())
                throw "Erro na leitura do arquivo Funcionarios.txt";
            //cout << salario << endl;
            leituraFuncionarios.ignore();
            getline(leituraFuncionarios, rua);
            //cout << rua << endl;
            leituraFuncionarios >> numero;
            if(leituraFuncionarios.fail())
                throw "Erro na leitura do arquivo Funcionarios.txt";
            //cout << numero << endl;
            leituraFuncionarios.ignore();
            if(!leituraFuncionarios.eof() && !leituraFuncionarios.fail())
                getline(leituraFuncionarios, bairro);
            else
                throw "Erro na leitura do arquivo Funcionarios.txt";
            //cout << bairro << endl;
        }
        catch(const char* e){
            cout << e << endl << endl;
            break;
        }

        pessoa[0][nFuncionarios] = new Funcionario();
        pessoa[0][nFuncionarios]->setNome(nome);
        pessoa[0][nFuncionarios]->setCpf(cpf);
        ((Funcionario *)pessoa[0][nFuncionarios])->setCargo(cargo);
        ((Funcionario *)pessoa[0][nFuncionarios])->setSalario(salario);
        endereco.setRua(rua);
        endereco.setNumero(numero);
        endereco.setBairro(bairro);
        pessoa[0][nFuncionarios]->setEndereco(endereco);

        nFuncionarios++;
    }
    leituraFuncionarios.close();

    //Leitura dos Pacientes
    string situacao;
    int idade;
    char sexo;

    leituraPacientes.open("Pacientes.txt", ios::in);
    if(!leituraPacientes.is_open())
        cout << "Erro ao abrir Pacientes.txt\n";

    while(!leituraPacientes.eof() && !leituraPacientes.fail()){
        try{
            getline(leituraPacientes, nome);
            //cout << nome << endl;
            leituraPacientes >> idade;
            if(leituraPacientes.fail())
                throw "Erro na leitura do arquivo Pacientes.txt";
            //cout << idade << endl;
            leituraPacientes.ignore();
            leituraPacientes >> sexo;
            if(!isalpha(sexo))
                throw "Erro na leitura do arquivo Pacientes.txt";
            //cout << sexo << endl;
            leituraPacientes.ignore();
            getline(leituraPacientes, cpf);
            //cout << cpf << endl;
            getline(leituraPacientes, situacao);
            //cout << situacao << endl;
            getline(leituraPacientes, rua);
            //cout << rua << endl;
            leituraPacientes >> numero;
            if(leituraPacientes.fail())
                throw "Erro na leitura do arquivo Pacientes.txt";
            //cout << numero << endl;
            leituraPacientes.ignore();
            if(!leituraPacientes.eof() && !leituraPacientes.fail())
                getline(leituraPacientes, bairro);
            else
                throw "Erro na leitura do arquivo Pacientes.txt";
            //cout << bairro << endl;
        }
        catch(const char* e){
            cout << e << endl << endl;
            break;
        }

        pessoa[1][nPacientes] = new Paciente();
        pessoa[1][nPacientes]->setNome(nome);
        ((Paciente *)pessoa[1][nPacientes])->setIdade(idade);
        ((Paciente *)pessoa[1][nPacientes])->setSexo(sexo);
        pessoa[1][nPacientes]->setCpf(cpf);
        ((Paciente *)pessoa[1][nPacientes])->setSituacao(situacao);
        endereco.setRua(rua);
        endereco.setNumero(numero);
        endereco.setBairro(bairro);
        pessoa[1][nPacientes]->setEndereco(endereco);

        nPacientes++;
    }

    //Menu
    do{
        if(opcaoGeral>=1 && opcaoGeral<=3)
            exibeMenuGeral();
        cin >> opcaoGeral;
        switch (opcaoGeral){
            case 1: //Funcionarios
                do{
                    tipo = 0;
                    if(opcao>=1 && opcao<=6)
                        exibeMenuFuncionario();
                    cin >> opcao;
                    cin.ignore();
                    switch (opcao){
                        case 1:
                            if(nFuncionarios==0){
                                cout << "Nao ha nenhum funcionario, e necessario cadastrar algum antes" << endl;
                                break;
                            }
                            for(int i = 0; i<nFuncionarios; i++)
                                cout << i+1 << " - " << pessoa[tipo][i]->getNome() << endl;
                            break;
                        case 2:
                            cout << "Digite o nome do funcionario que voce deseja exibir: ";
                            getline(cin, qualPessoa);
                            flag = 0;
                            for(int i = 0; i<nFuncionarios ;i++)
                                if(pessoa[tipo][i]->getNome().find(qualPessoa) != string::npos){
                                    pessoa[tipo][i]->exibeCadastro();
                                    flag=1;
                                }
                            if(!flag)
                                cout << "Funcionario nao encontrado" << endl;
                            break;
                        case 3:
                            cout << "Digite o nome do funcionario que voce deseja atualizar: ";
                            getline(cin, qualPessoa);
                            flag=0;
                            for(int i = 0; i<nFuncionarios; i++)
                                if(pessoa[tipo][i]->getNome().find(qualPessoa) != string::npos){
                                    ((Funcionario *)pessoa[tipo][i])->atualizaCadastro();
                                    flag=1;
                                    break;
                                }
                            if(!flag)
                                cout << "Funcionario nao encontrado" << endl;
                            break;
                        case 4:
                            nFuncionarios++;
                            pessoa[tipo][nFuncionarios - 1] = new Funcionario();
                            pessoa[tipo][nFuncionarios - 1]->preencheCadastro();
                            break;
                        case 5:
                            cout << "Informe o nome do funcionario que sera removido: ";
                            getline(cin, qualPessoa);
                            flag = 0;
                            for(int i = 0; i<nFuncionarios; i++){
                                if(pessoa[tipo][i]->getNome().find(qualPessoa) != string::npos){
                                    flag=1;
                                }
                                if(flag && i != nFuncionarios - 1){
                                    pessoa[tipo][i]->setNome(pessoa[tipo][i+1]->getNome());
                                    pessoa[tipo][i]->setCpf(pessoa[tipo][i+1]->getCpf());
                                    ((Funcionario *)pessoa[tipo][i])->setCargo(((Funcionario *)pessoa[tipo][i+1])->getCargo());
                                    ((Funcionario *)pessoa[tipo][i])->setSalario(((Funcionario *)pessoa[tipo][i+1])->getSalario());
                                    //
                                    ((Funcionario *)pessoa[tipo][i])->setEndereco(((Funcionario *)pessoa[tipo][i+1])->getEndereco());
                                }
                            }
                            if(flag){
                                nFuncionarios--;
                                //pessoa[tipo][nFuncionarios]->removeCadastro();
                                if(pessoa[tipo][nFuncionarios] != NULL){
                                    delete pessoa[tipo][nFuncionarios];
                                    pessoa[tipo][nFuncionarios] =  NULL;
                                }
                            }
                            else
                                cout << "Funcionario nao encontrado" << endl;
                            break;
                        case 6:
                            cout << "Retornando para o menu principal..." << endl << endl;
                            break;
                        default:
                                cout << "Numero invalido, digite um numero valido: ";
                            }

                }while(opcao!=6);
                break;
            case 2: //Pacientes
                do{
                    tipo = 1;
                    if(opcao>=1 && opcao<=6)
                        exibeMenuPaciente();
                    cin >> opcao;
                    cin.ignore();
                    switch (opcao){
                        case 1:
                            if(nPacientes==0){
                                cout << "Nao ha nenhum paciente, e necessario cadastrar algum antes" << endl;
                                break;
                            }
                            for(int i = 0; i<nPacientes; i++)
                                cout << i+1 << " - " << pessoa[tipo][i]->getNome() << endl;
                            break;
                        case 2:
                            cout << "Digite o nome do paciente que voce deseja exibir: ";
                            getline(cin, qualPessoa);
                            flag = 0;
                            for(int i = 0; i<nPacientes ;i++)
                                if(pessoa[tipo][i]->getNome().find(qualPessoa) != string::npos){
                                    pessoa[tipo][i]->exibeCadastro();
                                    flag=1;
                                }
                            if(!flag)
                                cout << "Paciente nao encontrado" << endl;
                            break;
                        case 3:
                            cout << "Digite o nome do paciente que voce deseja atualizar: ";
                            getline(cin, qualPessoa);
                            //getchar();
                            flag=0;
                            for(int i = 0; i<nPacientes; i++)
                                if(pessoa[tipo][i]->getNome().find(qualPessoa) != string::npos){
                                    ((Paciente *)pessoa[tipo][i])->atualizaCadastro();
                                    flag=1;
                                    break;
                                }
                            if(!flag)
                                cout << "Paciente nao encontrado" << endl;
                            break;
                        case 4:
                            nPacientes++;
                            pessoa[tipo][nPacientes - 1] = new Paciente();
                            pessoa[tipo][nPacientes - 1]->preencheCadastro();
                            break;
                        case 5:
                            cout << "Informe o nome do paciente que sera removido: ";
                            getline(cin, qualPessoa);
                            flag = 0;
                            for(int i = 0; i<nPacientes; i++){
                                if(pessoa[tipo][i]->getNome().find(qualPessoa) != string::npos){
                                    flag=1;
                                }
                                if(flag && i != nPacientes - 1){
                                    pessoa[tipo][i]->setNome(pessoa[tipo][i+1]->getNome());
                                    ((Paciente *)pessoa[tipo][i])->setIdade(((Paciente *)pessoa[tipo][i+1])->getIdade());
                                    ((Paciente *)pessoa[tipo][i])->setSexo(((Paciente *)pessoa[tipo][i+1])->getSexo());
                                    pessoa[tipo][i]->setCpf(pessoa[tipo][i+1]->getCpf());
                                    ((Paciente *)pessoa[tipo][i])->setSituacao(((Paciente *)pessoa[tipo][i+1])->getSituacao());
                                    //
                                    ((Paciente *)pessoa[tipo][i])->setEndereco(((Paciente *)pessoa[tipo][i+1])->getEndereco());
                                }
                            }
                            if(flag){
                                nPacientes--;
                                //pessoa[tipo][nPacientes]->removeCadastro();
                                if(pessoa[tipo][nPacientes] != NULL){
                                    delete pessoa[tipo][nPacientes];
                                    pessoa[tipo][nPacientes] =  NULL;
                                }
                            }
                            else
                                cout << "Paciente nao encontrado" << endl;
                            break;
                        case 6:
                            cout << "Retornando para o menu principal..." << endl << endl;
                            break;
                        default:
                                cout << "Numero invalido, digite um numero valido: ";
                            }
                }while(opcao!=6);
                break;
            case 3:
                cout << "Obrigado por usar nosso sistema de controle de hospitais!!" << endl;
                break;
            default:
                cout << "Numero invalido, digite um numero valido: ";
        }

    }while(opcaoGeral != 3);

    //Escrita dos Funcionarios
    escreveFuncionarios.open("Funcionarios.txt", ios::out);
    if(!escreveFuncionarios.is_open())
        cout << "Erro ao abrir Funcionarios.txt\n";

    for(int i = 0; i < nFuncionarios; i++){
        escreveFuncionarios << pessoa[0][i]->getNome() << endl;
        escreveFuncionarios << pessoa[0][i]->getCpf() << endl;
        escreveFuncionarios << ((Funcionario *)pessoa[0][i])->getCargo() << endl;
        escreveFuncionarios << ((Funcionario *)pessoa[0][i])->getSalario() << endl;
        escreveFuncionarios << pessoa[0][i]->getEndereco().getRua() << endl;
        escreveFuncionarios << pessoa[0][i]->getEndereco().getNumero() << endl;
        escreveFuncionarios << pessoa[0][i]->getEndereco().getBairro();
        if(i != nFuncionarios - 1)
            escreveFuncionarios << endl; //nao pode ficar uma linha solta no final do arquivo;
    }
    escreveFuncionarios.close();

    //Escrita dos pacientes
    escrevePacientes.open("Pacientes.txt", ios::out);
    if(!escrevePacientes.is_open())
        cout << "Erro ao abrir Pacientes.txt\n";

    for(int i = 0; i < nPacientes; i++){
        escrevePacientes << pessoa[1][i]->getNome() << endl;
        escrevePacientes << ((Paciente *)pessoa[1][i])->getIdade() << endl;
        escrevePacientes << ((Paciente *)pessoa[1][i])->getSexo() << endl;
        escrevePacientes << pessoa[1][i]->getCpf() << endl;
        escrevePacientes << ((Paciente *)pessoa[1][i])->getSituacao() << endl;
        escrevePacientes << pessoa[1][i]->getEndereco().getRua() << endl;
        escrevePacientes << pessoa[1][i]->getEndereco().getNumero() << endl;
        escrevePacientes << pessoa[1][i]->getEndereco().getBairro();
        if(i != nPacientes - 1)
            escrevePacientes << endl;
    }
    escrevePacientes.close();

    return 0;
}
