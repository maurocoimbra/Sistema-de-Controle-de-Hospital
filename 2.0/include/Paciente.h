#ifndef PACIENTE_H
#define PACIENTE_H

#include "Pessoa.h"

namespace dados{

//using namespace std;

class Paciente : public Pessoa
{
    public:
        Paciente();
        virtual ~Paciente();

        int getIdade();
        char getSexo();
        string getSituacao();
        void setIdade(int i);
        void setSexo(char s);
        void setSituacao(string s);

        void preencheCadastro();
        void exibeCadastro();
        void removeCadastro();
        void atualizaCadastro();

    private:
        int idade;
        char sexo;
        string situacao;
};

}
#endif // PACIENTE_H
