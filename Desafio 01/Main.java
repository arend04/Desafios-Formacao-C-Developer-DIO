
public class Main {
    public static void main(String[] args) {
        ContaBancaria contaCorrente = new ContaBancaria("Corrente", 1000);
        ContaBancaria contaSalario = new ContaBancaria("Salário", 2000);
        ContaBancaria contaPoupanca = new ContaBancaria("Poupança", 500);

        contaCorrente.sacar(500);
        contaSalario.sacar(1500);
        contaPoupanca.sacar(1000);
    }
}
