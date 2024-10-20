#include <iostream>
#include <string>

using namespace std;

class Cliente
{
private:
    string nome;
    string cpf;

public:
    Cliente(string nome, string cpf) : nome(nome), cpf(cpf) {}

    string getNome() const
    {
        return this->nome;
    }

    string getCPF() const
    {
        return this->cpf;
    }
};

class ContaBancaria
{
private:
    int numero;
    Cliente titular;
    double saldo;

public:
    // Construtor com saldo inicial opcional
    ContaBancaria(int numero, Cliente &titular, double saldo = 0.0)
        : numero(numero), titular(titular), saldo(saldo) {}

    // Getter para o número da conta
    int getNumero()
    {
        return this->numero;
    }

    // Métodos para depósito
    void depositar(double valor)
    {
        this->saldo += valor;
    }

    // Métodos para saque
    void sacar(double valor)
    {
        if (valor <= this->saldo)
        {
            this->saldo -= valor;
        }
        else
        {
            cout << "Saldo insuficiente" << endl;
        }
        this->saldo -= valor;
    }

    // Métodos para transferência para uma conta destino
    void transferir(double valor, ContaBancaria &contaDestino)
    {
        if (valor <= this->saldo)
        {
            this->saldo -= valor;
            contaDestino.depositar(valor);
            cout << "transferido " << valor << " para " << contaDestino.getNumero() << endl;
        }
        else
        {
            cout << "Saldo insuficiente" << endl;
        }
    }

    // Métodos para transferência para duas contas destino
    void transferir(double valor, ContaBancaria &contaDestino1, ContaBancaria &contaDestino2)
    {
        if (valor <= saldo)
        {
            this->saldo -= valor;
            contaDestino1.depositar(valor / 2);
            contaDestino2.depositar(valor / 2);
            cout << "transferido " << valor << " para " << contaDestino1.getNumero() << " e " << contaDestino2.getNumero() << endl;
        }
        else
        {
            cout << "Saldo insuficiente" << endl;
        }
    }

    void exibirSaldo()
    {
        cout << "Saldo atual da conta " << this->numero << ": R$" << saldo << endl;
    }

    void exibirInformacoes()
    {
        cout << "Conta: " << this - numero << endl;
        cout << "Titular: " << this->titular.getNome() << " (" << this->titular.getCPF() << ")" << endl;
        cout << "Saldo: R$" << this->saldo << endl;
        cout << endl;
    }
};

int main()
{
    // Criação dos clientes
    Cliente cliente1("Ana", "111.111.111-11");
    Cliente cliente2("Bruno", "222.222.222-22");
    Cliente cliente3("Carla", "333.333.333-33");
    // Criação das contas bancárias com saldos iniciais
    ContaBancaria conta1(1001, cliente1, 1000.0);
    ContaBancaria conta2(1002, cliente2);
    ContaBancaria conta3(1003, cliente3);
    // Exibe o saldo inicial da conta de Ana
    conta1.exibirSaldo();

    // Ana transfere R$200 para Bruno
    conta1.transferir(200.0, conta2);

    // Ana transfere R$300 divididos entre Bruno e Carla
    conta1.transferir(300.0, conta2, conta3);

    // Exibição dos saldos finais
    cout << endl;
    conta1.exibirInformacoes();
    conta2.exibirInformacoes();
    conta3.exibirInformacoes();

    return 0;
}
