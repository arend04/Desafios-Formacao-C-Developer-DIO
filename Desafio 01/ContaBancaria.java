public class ContaBancaria {
    private String tipo;
    private double saldo;

    public ContaBancaria(String tipo, double saldo) {
        this.tipo = tipo;
        this.saldo = saldo;
    }

    public String getTipo() {
        return tipo;
    }

    public double getSaldo() {
        return saldo;
    }

    public void sacar(double valor) {
        if (valor <= saldo) {
            saldo -= valor;
            System.out.println("Saque de " + valor + " realizado com sucesso na conta " + tipo);
        } else {
            System.out.println("Saldo insuficiente na conta " + tipo);
        }
    }
}
