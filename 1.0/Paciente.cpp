#include "Paciente.h"
#include <iostream>
using namespace std;

Paciente::Paciente(){
    //ctor
}

void Paciente::preencherCadastro(){
    cout << "Informe o nome do paciente: ";
    getline(cin,nome);
    cout << "Informe a idade do paciente: ";
    cin >> idade;
    getchar();
    cout << "Informe o sexo do paciente: ";
    cin >> sexo;
    getchar();
    cout << "Informe o cpf do paciente: ";
    getline(cin,cpf);
    cout << "Informe a situacao do paciente: ";
    getline(cin,situacao);
}

void Paciente::exibePaciente(){
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
    cout << "Sexo: " << sexo << endl;
    cout << "Cpf: " << cpf << endl;
    cout << "Situacao: " << situacao << endl << endl;
}

void Paciente::removeCadastro(){
    nome="";
    idade=0;
    sexo='0';
    cpf="";
    situacao="";
}

void Paciente::atualizaSituacao(){
    cout << "Informe a situacao atual do paciente " << nome << ": ";
    getline(cin,situacao);
}
/*
string Paciente::procuraNome(string n){
    return strstr(n,nome);
}
*/

string Paciente::getNome(){
    return nome;
}
int Paciente::getIdade(){
    return idade;
}
char Paciente::getSexo(){
    return sexo;
}
string Paciente::getCpf(){
    return cpf;
}
string Paciente::getSituacao(){
    return situacao;
}
void Paciente::setNome(string n){
    nome = n;
}
void Paciente::setIdade(int i){
    idade = i;
}
void Paciente::setSexo(char s){
    sexo = s;
}
void Paciente::setCpf(string c){
    cpf = c;
}
void Paciente::setSituacao(string s){
    situacao = s;
}
